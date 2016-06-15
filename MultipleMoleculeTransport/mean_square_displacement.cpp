#include "mean_square_displacement.h"

string ITOS(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}

void calculate_mean_square_displacement(bool& diff_flag, vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, int& current_time, int& time_origin, int& dt, vector<diffusion>& diff, string& output_string, int& number_of_species, vector<int>& s_loc)
{
	if (diff_flag == 0)
	{
		for (int species = 0; species < number_of_species; ++species)
		{
			double msd_av = 0;
			double dr_mag = 0;
			vector<double> dr(3, 0);

			for (int id = s_loc[species]; id < s_loc[species] + number_of_atoms[species]; id += atoms_per_molecule[species])
			{
				dr[0] = molecule[id].cX_ - molecule[id].cX0_;
				dr[1] = molecule[id].cY_ - molecule[id].cY0_;
				dr[2] = molecule[id].cZ_ - molecule[id].cZ0_;
				dr_mag = pow(dr[0], 2) + pow(dr[1], 2) + pow(dr[2], 2);
				msd_av += dr_mag;
			}
			msd_av /= number_of_molecules[species];

			int h = (current_time - time_origin) / dt;
			diff[h].av_[species] += msd_av;
			diff[h].N_[species] += 1;
		}
	}
	else
	{
		for (int species = 0; species < number_of_species; ++species)
		{
			ofstream output;
			string spec = ITOS(species);
			output.open(("diffusion." + output_string + "." + spec + ".dat").c_str(), ios::app);
			for (int h = 0; h < current_time / dt; ++h)
			{
				if (diff[h].N_[species] > 0)
				{
					diff[h].av_[species] = diff[h].av_[species] / diff[h].N_[species];
					output << h * dt << " " << diff[h].N_[species] << " " << diff[h].av_[species] << endl;
				}
				else
				{
					//do nothing
				}
			}
		}
	}
}