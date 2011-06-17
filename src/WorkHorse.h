// File: WorkHorse.h
// Original Author: Michael Imelfort 2011
// --------------------------------------------------------------------
//
// OVERVIEW:
//
// This class is responsible for "running" the algorithm
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

#ifndef WorkHorse_h
    #define WorkHorse_h

// system includes
#include <iostream>
#include <string>
#include <vector>
#include <map>

// local includes
#include "crass_defines.h"
#include "libcrispr.h"
#include "NodeManager.h"
#include "ReadHolder.h"

// typedefs
typedef std::map<std::string, NodeManager *> DR_List;
typedef std::map<std::string, NodeManager *>::iterator DR_ListIterator;
typedef std::vector<ReadHolder *> ReadList;
typedef std::vector<ReadHolder *>::iterator ReadListIterator;

class WorkHorse {
    public:
        WorkHorse (const options * opts, std::string outDir) { mOpts = opts; mOutFileDir = outDir; }
        ~WorkHorse();
        
        // do all the work!
        int doWork(std::vector<std::string> seqFiles);

        //**************************************
        // file IO
        //**************************************
        //void write_spacerID(direct_repeat &dr_match, kseq_t *seq);
        //void write_direct_repeatID(direct_repeat &dr_match, kseq_t *seq);
        void writeLookupToFile(string &outFileName, lookupTable &outLookup);
        
    private:
        
        void clearReadLists(void);
        void printFileLookups(std::string fileName, lookupTable &kmerLookup , lookupTable &patternsLookup, lookupTable &spacerLookup);
        
        // members
        DR_List mDRs;                       // list of nodemanagers, cannonical DRs
        ReadList mReads;                    // reads containing possible DRs
        
        const options * mOpts;                    // search options
        std::string mOutFileDir;            // where to spew text to
};

#endif //WorkHorse_h