/*
 * Copyright: (C) 2012 Istituto Italiano di Tecnologia (IIT)
 * Author: Lorenzo Natale
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */

#include <yarp/os/Network.h>
#include <yarp/os/Time.h>
#include <yarp/os/ResourceFinder.h>

#include <string>
#include <iostream>

using namespace yarp::os;

using namespace std;
int main(int argc, char *argv[]) 
{
    Network yarp;

    ResourceFinder rf;
    rf.setVerbose();
    rf.setDefaultConfigFile("or.ini");
    rf.setDefaultContext("orBottle");
    rf.configure(argc, argv);
        
    ConstString robotName=rf.find("robot").asString();
    ConstString model=rf.findFile("model");
    
    cout<<"Running with:"<<endl;
    cout<<"robot: "<<robotName.c_str()<<endl;
    
    if (model=="")
    {
        cout<<"Sorry no model was found, check config parameters"<<endl;
        return -1;
    }

    cout << "Using object model: " << model.c_str() << endl;

    int times=4;
    while(times--)
    {
        cout << ".";
        Time::delay(0.5);
    }

    cout << "done!" <<endl;

    return 0;
}
