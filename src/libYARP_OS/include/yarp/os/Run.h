// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

/*
 * Copyright (C) 2007 Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the GNU GPL v2.0.
 *
 */

#ifndef _YARP2_RUN_
#define _YARP2_RUN_

#ifndef DOXYGEN_SHOULD_SKIP_THIS

namespace yarp {
  namespace os {
    class Run;
  }
}


// watch out for ACE randomly redefining main, depending on configuration
#ifdef main
#undef main
#endif

/**
 * Starting and stopping processes.
 * Experimental.  Use and lose.
 */
class yarp::os::Run {
public:
    static int main(int argc, char *argv[]);

protected:
	static bool checkBash(String& workdir);
	static int run();
	static int runServerBash(ConstString& portname,String& workdir);
	#ifdef WIN32
	static int runServerDos(ConstString& portname,String& workdir);
	#endif
	static int runConnect(Searchable& config);
	static int runClient(Searchable& config);
};

#endif /*DOXYGEN_SHOULD_SKIP_THIS*/


#endif
