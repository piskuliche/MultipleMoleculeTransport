#include "read_file.h"

//Subroutine to read in lammps dump information.

void read_file(int& number_of_species, vector<int>& number_of_atoms, vector<atom>& molecule, string& filename, int& current_time, int& time_dump_freq, int& start_time,int& total_atoms, vector<int>& s_loc)
{
	//Opens the input file (of filename)
	ifstream input;
	input.open(filename);
	if (input.fail())
	{
		cerr << "Error: Input file did not open" << endl;
	}
	
	//Loops over the number of species

	//Declares the lines taken up by the LAMMPS Header, and calculates the lines to skip.
	int header = 9;
	int skip = (total_atoms + header) * (current_time - start_time) / time_dump_freq + 9;
	string bufferstring;
	//Loops over the number of atoms for each species

	for (int j = 0; j < skip; ++j)
	{
		getline(input, bufferstring);
	}
	for (int i = 0; i < number_of_species; ++i)
	{
		for (int j = s_loc[i]; j < s_loc[i] + number_of_atoms[i]; ++j)
		{
			//moves the skip to zero.
			int tmp = j;
			input >> molecule[tmp].id_ >> molecule[tmp].mol_ >> molecule[tmp].type_ >> molecule[tmp].Q_ >> molecule[tmp].X_ >> molecule[tmp].Y_ >> molecule[tmp].Z_;
		}
	}
	
	
}