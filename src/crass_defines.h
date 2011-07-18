// File: crass_defines.h
// Original Author: Connor Skennerton on 7/05/11
// --------------------------------------------------------------------
//
// OVERVIEW:
//
// The one stop shop for all your global definition needs!
// 
// --------------------------------------------------------------------
//  Copyright  2011 Michael Imelfort and Connor Skennerton
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
// --------------------------------------------------------------------
//
//                        A
//                       A B
//                      A B R
//                     A B R A
//                    A B R A C
//                   A B R A C A
//                  A B R A C A D
//                 A B R A C A D A
//                A B R A C A D A B 
//               A B R A C A D A B R  
//              A B R A C A D A B R A 
//
// --------------------------------------------------------------------

#ifndef __CRASSDEFINES_H
    #define __CRASSDEFINES_H

#include <string>
#include <getopt.h>
// --------------------------------------------------------------------
 // PROGRAM NAME AND VERISON INFORMATION
// --------------------------------------------------------------------
#define CRASS_DEF_PRG_NAME                      "crass"
#define CRASS_DEF_LONG_NAME                     "CRisprASSembler"
#define CRASS_DEF_VERSION                       "0.0.1"
#define CRASS_DEF_MAJOR_VERSION                 0
#define CRASS_DEF_MINOR_VERSION                 1
#define CRASS_DEF_REVISION                      0
// --------------------------------------------------------------------
 // STRING LENGTH / MISMATCH / CLUSTER SIZE PARAMETERS
// --------------------------------------------------------------------
#define CRASS_DEF_READ_LENGTH_CUTOFF            (200.0)             // The length of read where the multipattern matcher would become insignificant. 
                                                                    //   ie where it is very likely that there is 2 full repeat-spacer-repeat units
#define CRASS_DEF_MAX_PATTERN_LENGTH            1024                // How long can a DR be?
#define CRASS_DEF_MAX_LOST_SOULS_MISMATCHES     2
#define CRASS_DEF_MAX_CLUSTER_SIZE_FOR_SW       30                  // Maximum number of cluster reps we will all vs all sw for
#define CRASS_DEF_MIN_SW_ALIGNMENT_RATIO        (0.85)              // SW alignments need to be this percentage of the original query to be considered real
#define CRASS_DEF_SW_SEARCH_EXT                 8
#define CRASS_DEF_LOW_COMPLEXITY_THRESHHOLD     0.75
#define CRASS_DEF_KMER_SIZE                     7
#define CRASS_DEF_K_CLUST_MIN                   12
// --------------------------------------------------------------------
// HARD CODED PARAMS FOR FINDING TRUE DRs
// --------------------------------------------------------------------
#define CRASS_DEF_NUM_KMERS_4_MODE              (5)                 // find the top XX occuring in the DR
#define CRASS_DEF_NUM_KMERS_4_MODE_HALF         (CRASS_DEF_NUM_KMERS_4_MODE - (CRASS_DEF_NUM_KMERS_4_MODE/2)) // Ceil of 50% of CRASS_DEF_NUM_KMERS_4_MODE
#define CRASS_DEF_MIN_READ_DEPTH                4                   // read depth used for consensus building
#define CRASS_DEF_CONS_CUT_OFF                  (0.75)              // minimum identity to extend a DR from the "zone" outwards
#define CRASS_DEF_COLLAPSED_THRESHOLD           (0.3)               // in the event that clustering has collapsed two DRs into one, this number is used to plait them apart
// --------------------------------------------------------------------
  // FILE IO
// --------------------------------------------------------------------
#define CRASS_DEF_FASTQ_FILENAME_MAX_LENGTH     1024
#define CRASS_DEF_DEF_KMER_LOOKUP_EXT           "crass_kmers.txt"
#define CRASS_DEF_DEF_PATTERN_LOOKUP_EXT        "crass_direct_repeats.txt"
#define CRASS_DEF_DEF_SPACER_LOOKUP_EXT         "crass_spacers.txt"
// --------------------------------------------------------------------
 // USER OPTION STRUCTURE -- TODO: REMOVE THIS!
// --------------------------------------------------------------------
#define CRASS_DEF_MAX_DELIM_LENGTH              10                  // delimiter used in stats report
#define CRASS_DEF_MIN_DR_SIZE                   23                  // minimum direct repeat size
#define CRASS_DEF_MAX_DR_SIZE                   45                  // maximum direct repeat size
#define CRASS_DEF_MIN_SPACER_SIZE               26                  // minimum spacer size
#define CRASS_DEF_MAX_SPACER_SIZE               50                  // maximum spacer size
#define CRASS_DEF_NUM_DR_ERRORS                 0                   // maxiumum allowable errors in direct repeat

typedef struct {
    int count;
    bool detect;
    int logger_level;
    bool illumina;
    bool fourFiveFour;
    bool sanger;
    bool genome;
    bool report_stats;
    int lowDRsize;
    int highDRsize;
    int lowSpacerSize;
    int highSpacerSize;
    int max_mismatches;
    std::string output_fastq;
    char delim[CRASS_DEF_MAX_DELIM_LENGTH];                         // delimiter used in stats report
    char * pat_file;
    int kmer_size;
} options;


static struct option long_options [] = {

    {"minDR", required_argument, NULL, 'd'},
    {"maxDR", required_argument, NULL, 'D'},
    {"minSpacer", required_argument, NULL, 's'},
    {"maxSpacer", required_argument, NULL, 'S'},
    {"logLevel", required_argument, NULL, 'l'},
    {"maxMismatches", required_argument, NULL, 'm'},
    {"version", no_argument, NULL, 'V'},
    {"kmerCount", required_argument, NULL, 'k'},
    {"outDir", required_argument, NULL, 'o'},
    {"help", no_argument, NULL, 'h'},
    {"reportStats", no_argument, NULL, 'r'},
    {"dumpReads", no_argument, NULL, 0},
    {"454", no_argument, NULL, 0},
    {"illumina", no_argument, NULL, 0},
    {"sanger", no_argument, NULL, 0},
    {"genome", no_argument, NULL, 0}
    

};
// --------------------------------------------------------------------
#endif // __CRASSDEFINES_H
