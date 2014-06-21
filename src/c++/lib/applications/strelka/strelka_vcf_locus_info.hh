// -*- mode: c++; indent-tabs-mode: nil; -*-
//
// Starka
// Copyright (c) 2009-2014 Illumina, Inc.
//
// This software is provided under the terms and conditions of the
// Illumina Open Source Software License 1.
//
// You should have received a copy of the Illumina Open Source
// Software License 1 along with this program. If not, see
// <https://github.com/sequencing/licenses/>
//

///
/// \author Chris Saunders
///

#pragma once

#if 0
#include "blt_common/position_snp_call_pprob_digt.hh"
#include "starling_common/align_path.hh"
#include "starling_common/starling_indel_call_pprob_digt.hh"
#include "starling_common/starling_shared.hh"

#include <bitset>
#include <iosfwd>
#include <map>
#endif

#include <cassert>

#include <bitset>
#include <iosfwd>


namespace STRELKA_VCF_FILTERS
{

enum index_t
{
    HighDepth,
    SIZE
};

inline
const char*
get_label(const unsigned idx)
{
    switch (idx)
    {
    case HighDepth:
        return "HighDepth";
        //return "DP";
    default:
        assert(false && "Unknown vcf filter id");
        return nullptr;
    }
}
}



struct strelka_shared_modifiers
{
    strelka_shared_modifiers()
    {
        clear();
    }

    void
    set_filter(const STRELKA_VCF_FILTERS::index_t i)
    {
        filters.set(i);
    }

    void
    write_filters(std::ostream& os) const;

    void
    clear()
    {
        filters.reset();
    }

    std::bitset<STRELKA_VCF_FILTERS::SIZE> filters;
};


std::ostream& operator<<(std::ostream& os,const strelka_shared_modifiers& shmod);
