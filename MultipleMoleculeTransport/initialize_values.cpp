#include "initialize_values.h"

void initialize_values(vector<int>& number_of_molecules, vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, int& number_of_species, int& start_time, int& end_time, int& time_dump_freq, vector<int>& s_loc)
{


	for (int i = 0; i < number_of_species; ++i)
	{
		number_of_molecules[i] = number_of_atoms[i] / atoms_per_molecule[i];
		diff.resize((end_time - start_time) / time_dump_freq);
		reor.resize((end_time - start_time) / time_dump_freq);
		for (int k = s_loc[i]; k < s_loc[i]+number_of_atoms[i]; ++k)
		{
			molecule[k].id_=0;
			molecule[k].mol_=0;
			molecule[k].type_=0;
			molecule[k].Q_=0;
			molecule[k].X_=0;
			molecule[k].Y_=0;
			molecule[k].Z_=0;
			molecule[k].cX_=0;
			molecule[k].cX0_=0;
			molecule[k].cY_=0;
			molecule[k].cY0_=0;
			molecule[k].cZ_=0;
			molecule[k].cZ0_=0;
			molecule[k].eX_=0;
			molecule[k].eX0_=0;
			molecule[k].eY_=0;
			molecule[k].eY0_=0;
			molecule[k].eZ_=0;
			molecule[k].eZ0_=0;
			molecule[k].mux_=0;
			molecule[k].mux0_=0;
			molecule[k].muy_=0;
			molecule[k].muy0_=0;
			molecule[k].muz_=0;
			molecule[k].muz0_=0;
			molecule[k].name_;
		}
		// this could cause some problems
		for (int j = 0; j < ((end_time - start_time) / time_dump_freq); ++j)
		{
			diff[j].av_.resize(number_of_species);
			diff[j].sdv_.resize(number_of_species);
			diff[j].N_.resize(number_of_species);
			reor[j].c1av_.resize(number_of_species);
			reor[j].c1sdv_.resize(number_of_species);
			reor[j].c1N_.resize(number_of_species);
			reor[j].c2av_.resize(number_of_species);
			reor[j].c2sdv_.resize(number_of_species);
			reor[j].c2N_.resize(number_of_species);
			diff[j].av_[i] = 0;
			diff[j].sdv_[i] = 0;
			diff[j].N_[i] = 0;
			diff[j].av_val_.resize((end_time - start_time) / time_dump_freq);
			reor[j].c1av_[i] = 0;
			reor[j].c1sdv_[i] = 0;
			reor[j].c2av_[i] = 0;
			reor[j].c2sdv_[i] = 0;
			reor[j].c1N_[i] = 0;
			reor[j].c2N_[i] = 0;
			reor[j].c1val_.resize((end_time - start_time) / time_dump_freq);
			reor[j].c2val_.resize((end_time - start_time) / time_dump_freq);
		}
	}
}