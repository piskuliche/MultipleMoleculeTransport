#include "reorientation_correlation.h"

double dotproduct(double& value1x, double& value1y, double& value1z, double& value2x, double& value2y, double& value2z)
{
	double dotresult;
	dotresult = (value1x * value2x) + (value1y * value2y) + (value1z * value2z);
	return dotresult;
}

double legendre_polynomial(int& order, double& x)
{
	double Pn = 0;

	if (order == 0)
	{
		Pn = 1.0;
	}
	else if (order == 1)
	{
		Pn = x;

	}
	else if (order == 2)
	{
		Pn = 0.5 * (3 * pow(x, 2) - 1);
	}
	else
	{
		cerr << "Error in reorientationdynamics.cpp: Legendre polynomial order out of bounds." << endl;
		Pn = NAN;
	}
	return Pn;
}

string IToS(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}

void calculate_reorientation_correlation_function(bool reorient_flag,vector<int>& number_of_atoms, vector<int>& number_of_molecules, vector<int>& atoms_per_molecule, vector<atom>& molecule, int& current_time, int& time_origin, int& dt, vector<reorientation>& reor, string& output_string, int& number_of_species, vector<int>& s_loc)
{
	if (reorient_flag == 0)
	{
		double e_dot_e = 0;
		double c1_av = 0;
		double c2_av = 0;
		int molec = 0;
		int order = 0;
		for (int species = 0; species < number_of_species; ++species)
		{
			for (int id = s_loc[species]; id < s_loc[species] + number_of_atoms[species]; id += atoms_per_molecule[species])
			{
				e_dot_e = dotproduct(molecule[id].eX_, molecule[id].eY_, molecule[id].eZ_, molecule[id].eX0_, molecule[id].eY0_, molecule[id].eZ0_);
				c1_av += legendre_polynomial(order, e_dot_e);
				c2_av += legendre_polynomial(order, e_dot_e);
			}
			c1_av /= number_of_molecules[species];
			c2_av /= number_of_molecules[species];

			int h = ((current_time - time_origin) / dt);
			reor[h].c1av_[species] += c1_av;
			reor[h].c1N_[species] += 1;
			reor[h].c2av_[species] += c2_av;
			reor[h].c2N_[species] += 1;
		}
	}
	else
	{
		for (int species = 0; species < number_of_species; ++species)
		{
			ofstream output;
			string spec = IToS(species);
			output.open(("reorientation." + output_string + "." + spec + ".dat").c_str(), ios::app);
			for (int h = 0; h < current_time / dt; ++h)
			{
				if (reor[h].c1N_[species] > 0)
				{
					reor[h].c1av_[species] = reor[h].c1av_[species] / reor[h].c1N_[species];
					reor[h].c2av_[species] = reor[h].c2av_[species] / reor[h].c2N_[species];
					output << h*dt << " " << reor[h].c1N_[species] << " " << reor[h].c1av_[species] << " " << reor[h].c2av_[species] << endl;
				}
				else
				{
					//do nothing.
				}
			}
		}
		
	}
}