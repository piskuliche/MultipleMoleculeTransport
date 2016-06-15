#include "main.h"
#include "inner_time_loop.h"
#include "time_origin_loop.h"
#include "initialize_values.h"
#include "read_parameter.h"
#include "read_file.h"

int main()
{
	/*Initializations*/
	/*---------------*/
	//ints
	int n_corr = 0;
	int box_side_length = 0;
	int start_time = 0;
	int end_time = 0;
	int time_dump_freq = 0;
	int bin_length = 0;
	int calc_every = 0;
	int dt = 0;
	int lines = 0;
	int number_of_species = 0;
	int total_atoms = 0;
	//vectors
	vector<atom> molecule; //Vector of class atom: Holds all atoms of all species (s1, s2..)
	vector<diffusion> diff; // holds diffusion info
	vector<reorientation> reor; //holds reorientation info
	vector<double> mass; //temporary vector to hold mass. Unused past read_parameter().
	vector<int> number_of_atoms; //Holds the number of atoms of each species (i.e. Nbr Molecs * atoms per molec)
	vector<int> atoms_per_molecule; //Holds the atoms per molecule of each species (i.e. MeOH has "3")
	vector<int> number_of_molecules; //Holds the number of molecules of each species
	vector<int> type; //Holds the type of the molecule of each species
	//currently 0 = EO, 1 = MeOH
	vector<int> s_loc; //takes the form of a vector of size # species, holding starting index for each species i.e. s1 always starts with 0, s2 starts with nbr_atoms[s1], etc.

	//strings
	string filename = "default.dat";
	string compound = "test";
	string output_string;
	//read parameter input

	read_parameter(number_of_atoms, atoms_per_molecule, number_of_molecules, type, number_of_species, box_side_length, time_dump_freq, start_time, end_time, n_corr, filename, mass, bin_length, calc_every, dt, lines, molecule, total_atoms, s_loc);

	initialize_values(number_of_molecules, number_of_atoms, atoms_per_molecule, molecule, reor, diff, number_of_species, start_time, end_time, time_dump_freq, s_loc);
	dt = time_dump_freq * calc_every;
	LoopTimeOrigin(number_of_atoms, atoms_per_molecule, number_of_molecules, molecule, reor, diff, start_time, end_time, dt, time_dump_freq, output_string, filename, type, number_of_species, total_atoms, s_loc);
}