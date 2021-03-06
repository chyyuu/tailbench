/* -*- mode:C++; c-basic-offset:4 -*-
     Shore-kits -- Benchmark implementations for Shore-MT
   
                       Copyright (c) 2007-2009
      Data Intensive Applications and Systems Labaratory (DIAS)
               Ecole Polytechnique Federale de Lausanne
   
                         All Rights Reserved.
   
   Permission to use, copy, modify and distribute this software and
   its documentation is hereby granted, provided that both the
   copyright notice and this permission notice appear in all copies of
   the software, derivative works or modified versions, and any
   portions thereof, and that both notices appear in supporting
   documentation.
   
   This code is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. THE AUTHORS
   DISCLAIM ANY LIABILITY OF ANY KIND FOR ANY DAMAGES WHATSOEVER
   RESULTING FROM THE USE OF THIS SOFTWARE.
*/

/** @file:   dora_tpcc_client.h
 *
 *  @brief:  Defines the client for the DORA TPCC benchmark
 *
 *  @author: Ippokratis Pandis, May 2009
 */

#ifndef __DORA_TPCC_CLIENT_H
#define __DORA_TPCC_CLIENT_H


#include "workload/tpcc/tpcc_const.h"
#include "dora/tpcc/dora_tpcc.h"

using namespace shore;


ENTER_NAMESPACE(dora);



/******************************************************************** 
 *
 * @class: dora_tpcc_client_t
 *
 * @brief: The DORA TPC-C kit smthread-based test client class
 *
 ********************************************************************/

class dora_tpcc_client_t : public base_client_t 
{
private:
    // workload parameters
    DoraTPCCEnv* _tpccdb;    
    int _wh;
    double _qf;

public:

    dora_tpcc_client_t() { }     

    dora_tpcc_client_t(c_str tname, const int id, DoraTPCCEnv* env, 
                       const MeasurementType aType, const int trxid, 
                       const int numOfTrxs, 
                       processorid_t aprsid, const int sWH, const double qf)  
	: base_client_t(tname,id,env,aType,trxid,numOfTrxs,aprsid),
          _tpccdb(env), _wh(sWH), _qf(qf)
    {
        assert (env);
        assert (_wh>=0 && _qf>0);
    }

    ~dora_tpcc_client_t() { }

    // every client class should implement this function
    static int load_sup_xct(mapSupTrxs& map);

    // INTERFACE 

    w_rc_t submit_one(int xct_type, int xctid);    
    
}; // EOF: dora_tpcc_client_t



EXIT_NAMESPACE(dora);

#endif /** __DORA_TPCC_CLIENT_H */
