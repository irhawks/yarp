// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Author: Daniel Krieg krieg@fias.uni-frankfurt.de
 * Copyright (C) 2010 Daniel Krieg
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 *
 */

#ifndef _YARP_MPIP2PCARRIER_
#define _YARP_MPIP2PCARRIER_

#include <yarp/os/impl/MpiCarrier.h>
#include <yarp/os/impl/MpiP2PStream.h>

namespace yarp {
    namespace os {
        namespace impl {
            class MpiP2PCarrier;
        }
    }
}

/**
 * Communicating between ports via MPI: Point-to-Point version
 * Supports replies.
 *
 * @warning Seems to work, but still experimental.
 */
class yarp::os::impl::MpiP2PCarrier : public MpiCarrier {
public:
    MpiP2PCarrier() : MpiCarrier() {
        target = "MPI_____";
    }
    virtual ~MpiP2PCarrier() {
        delete comm;
    }
    Carrier *create() {
        return new MpiP2PCarrier();
    }
    void createStream(String name) {
        comm = new MpiComm(name);
        stream = new MpiP2PStream(name, comm);
    }
    String getName() {
        return "mpi";}
    bool supportReply() {
        return true;}


};

#endif //_YARP_MPIP2PCARRIER_

