#include "dipole_moment.h"

double midpoint(double& value1, double& value2)
{
	double mp = (value1 + value2) / 2.0;
	return mp;
}

double normalize(double& x, double& y, double& z)
{
	double norm_factor = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	return norm_factor;
}

void calculate_dipole_moment(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<atom>& molecule, int& current_time, int& time_origin, vector<int>& type, int& number_of_species, vector<int>& s_loc)
{
	vector<double> rtmp(3, 0);
	double norm = 0;

	for (int species = 0; species < number_of_species; ++species)
	{
		for (int id = s_loc[species]; id < s_loc[species]+number_of_atoms[species]; id += atoms_per_molecule[species])
		{

			if (type[species] == 0)
			{
				rtmp[0] = midpoint(molecule[id].X_, molecule[id + 1].X_);
				rtmp[1] = midpoint(molecule[id].Y_, molecule[id + 1].Y_);
				rtmp[2] = midpoint(molecule[id].Y_, molecule[id + 1].Y_);
				rtmp[0] -= molecule[id + 2].X_;
				rtmp[1] -= molecule[id + 2].Y_;
				rtmp[2] -= molecule[id + 2].Z_;
				norm = normalize(rtmp[0], rtmp[1], rtmp[2]);
				rtmp[0] /= norm;
				rtmp[1] /= norm;
				rtmp[2] /= norm;

				molecule[id].eX_ = rtmp[0];
				molecule[id].eY_ = rtmp[1];
				molecule[id].eZ_ = rtmp[2];

				if (current_time == time_origin)
				{
					molecule[id].eX0_ = molecule[id].eX_;
					molecule[id].eY0_ = molecule[id].eY_;
					molecule[id].eZ0_ = molecule[id].eZ_;
				}
			}
			else
			{
				rtmp[0] = molecule[id + 1].X_ - molecule[id + 2].X_;
				rtmp[1] = molecule[id + 1].Y_ - molecule[id + 2].Y_;
				rtmp[2] = molecule[id + 1].Z_ - molecule[id + 2].Z_;
				norm = normalize(rtmp[0], rtmp[1], rtmp[2]);
				rtmp[0] /= norm;
				rtmp[1] /= norm; 
				rtmp[2] /= norm;

				molecule[id].eX_ = rtmp[0];
				molecule[id].eY_ = rtmp[1];
				molecule[id].eZ_ = rtmp[2];

				if (current_time == time_origin)
				{
					molecule[id].eX0_ = molecule[id].eX_;
					molecule[id].eY0_ = molecule[id].eY_;
					molecule[id].eZ0_ = molecule[id].eZ_;
				}
				
			}
		}
	}
}