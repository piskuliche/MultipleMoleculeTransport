#pragma once
#ifndef toloop_H
#define toloop_H
#include "main.h"
#include "inner_time_loop.h"

void LoopTimeOrigin(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, int& start_time, int& end_time, int& dt, int& time_dump_freq, string& output_string, string& filename, vector<int>& type, int& number_of_species,int& total_atoms, vector<int>& s_loc);

#endif