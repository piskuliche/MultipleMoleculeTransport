#include "center_of_mass.h"

void calculate_center_of_mass(vector<atom>& molecule, vector<int>& number_of_atoms, vector<int>& number_of_molecules, vector<int>& atoms_per_molecule, int& current_time, int& time_origin, int& number_of_species, vector<int>& s_loc)
{
	for (int species = 0; species < number_of_species; ++species)
	{
		for (int id = s_loc[species]; id < s_loc[species]+number_of_atoms[species]; id += atoms_per_molecule[species])
		{
			ofstream out;
			vector<double> top_sum (3, 0);
			vector<double> bot_sum(3, 0);
			vector<double> c(3, 0);
			for (int apm = 0; apm < atoms_per_molecule[species]; ++apm)
			{
				top_sum[0] += molecule[apm + id].X_ * molecule[apm + id].M_;
				top_sum[1] += molecule[apm + id].Y_ * molecule[apm + id].M_;
				top_sum[2] += molecule[apm + id].Z_ * molecule[apm + id].M_;
				bot_sum[0] += molecule[apm + id].M_;
				bot_sum[1] += molecule[apm + id].M_;
				bot_sum[2] += molecule[apm + id].M_;
			}
			c[0] = top_sum[0] / bot_sum[0];
			c[1] = top_sum[1] / bot_sum[1];
			c[2] = top_sum[2] / bot_sum[2];

			for (int apm = 0; apm < atoms_per_molecule[species]; ++apm)
			{
				molecule[apm + id].cX_ = c[0];
				molecule[apm + id].cY_ = c[1];
				molecule[apm + id].cZ_ = c[2];
			}

			if (current_time == time_origin)
			{
				molecule[id].cX0_ = molecule[id].cX_;
				molecule[id].cY0_ = molecule[id].cY_;
				molecule[id].cZ0_ = molecule[id].cZ_;
			}
		}
	}
}