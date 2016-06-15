#include "inner_time_loop.h"

void LoopInnerTime(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, string& filename, bool& flag, int& start_time, int& end_time, int& dt, int& time_origin, int& total_time, int& time_dump_freq, string& output_string, vector<int>& type, int& number_of_species,int& total_atoms, vector<int>& s_loc)
{
	for (int current_time = time_origin; current_time < time_origin + total_time / 2.0; current_time += dt)
	{
		read_file(number_of_species, number_of_atoms, molecule, filename, current_time, time_dump_freq, start_time, total_atoms, s_loc);
		calculate_center_of_mass(molecule, number_of_atoms, number_of_molecules, atoms_per_molecule, current_time, time_origin, number_of_species, s_loc);
		calculate_dipole_moment(number_of_atoms, atoms_per_molecule, molecule, current_time, time_origin, type, number_of_species, s_loc);
		calculate_mean_square_displacement(flag, number_of_atoms, atoms_per_molecule, number_of_molecules, molecule, current_time, time_origin, dt, diff, output_string, number_of_species, s_loc);
		calculate_reorientation_correlation_function(flag, number_of_atoms, number_of_molecules, atoms_per_molecule, molecule, current_time, time_origin, dt, reor, output_string, number_of_species, s_loc);
	}
}