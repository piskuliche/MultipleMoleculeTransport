#include "time_origin_loop.h"

string IntToString(int a)
{
	ostringstream temp;
	temp << a;
	return temp.str();
}

void LoopTimeOrigin(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, int& start_time, int& end_time, int& dt, int& time_dump_freq, string& output_string, string& filename, vector<int>& type, int& number_of_species, int& total_atoms, vector<int>& s_loc)
{
	bool flag = 0;
	int total_time = end_time - start_time;
	if (total_time <= 0) { cerr << "Error: Total time is less than Zero." << endl; }
	for (int time_origin = start_time; time_origin < start_time + total_time / 2.0; time_origin += 10 * dt)
	{
		cout << time_origin << endl;
		output_string = IntToString(start_time);
		LoopInnerTime(number_of_atoms, atoms_per_molecule, number_of_molecules, molecule, reor, diff, filename, flag, start_time, end_time, dt, time_origin, total_time, time_dump_freq, output_string, type, number_of_species,total_atoms,s_loc);
	}
	flag = 1;
	calculate_reorientation_correlation_function(flag, number_of_atoms, number_of_molecules, atoms_per_molecule, molecule, total_time, start_time, dt, reor, output_string, number_of_species, s_loc);
	calculate_mean_square_displacement(flag, number_of_atoms, atoms_per_molecule, number_of_molecules, molecule, total_time, start_time, dt, diff, output_string, number_of_species, s_loc);
}