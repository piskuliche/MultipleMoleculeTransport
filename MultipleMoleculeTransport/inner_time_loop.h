#pragma once
#ifndef tiloop_H
#define tiloop_H
#include "main.h"
#include "dipole_moment.h"
#include "reorientation_correlation.h"
#include "read_file.h"
#include "center_of_mass.h"
#include "mean_square_displacement.h"

void LoopInnerTime(vector<int>& number_of_atoms, vector<int>& atoms_per_molecule, vector<int>& number_of_molecules, vector<atom>& molecule, vector<reorientation>& reor, vector<diffusion>& diff, string& filename, bool& flag, int& start_time, int& end_time, int& dt, int& time_origin, int& total_time, int& time_dump_freq, string& output_string, vector<int>& type, int& number_of_species,int& total_atoms, vector<int>& s_loc);

#endif