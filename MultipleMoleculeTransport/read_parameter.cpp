#include "read_parameter.h"

void read_parameter(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<int>& type, int& number_of_species, int& box_side, int& dump_freq, int& start_time, int& end_time, int& n_corr, string& filename, vector<double>& mass, int& bin_length, int& calc_every, int& dt, int& lines, vector<atom>& molecule, int& total_atoms, vector<int>& s_loc)
{
	ifstream param;
	param.open("tmp.txt");
	if (param.fail())
	{
		cerr << "Error: Parameter File Open Failed." << endl;
	}
	param >> number_of_species >> box_side >> dump_freq >> start_time >> end_time >> n_corr >> filename >> bin_length >> calc_every;

	type.resize(number_of_species);
	number_of_atoms.resize(number_of_species);
	number_of_molecules.resize(number_of_species);
	atoms_per_molecule.resize(number_of_species);
	
	for (int i = 0; i < number_of_species;++i)
	{
		param >> type[i] >> atoms_per_molecule[i] >> number_of_atoms[i];
		total_atoms += number_of_atoms[i];
		mass.resize(atoms_per_molecule[i]);
		if (i = 0)
		{
			s_loc.push_back(0);
		}
		else
		{
			int sum = 0;
			for (int j = 0; j < i; ++j)
			{
				sum += number_of_atoms[j];
			}
			s_loc.push_back(sum);
		}
	}
	molecule.resize(total_atoms);
	for (int i = 0; i < number_of_species; ++i)
	{
		for (int m = 0; m < atoms_per_molecule[i]; ++m)
		{
			param >> mass[m];
		}
		for (int t = s_loc[i]; t < s_loc[i] + number_of_atoms[i]; ++t)
		{
			molecule[t].M_ = mass[t%atoms_per_molecule[i]];
		}
	}
	
}