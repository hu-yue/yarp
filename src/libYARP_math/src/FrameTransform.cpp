/*
* Copyright (C) 2016 Istituto Italiano di Tecnologia (IIT)
* Authors: Marco Randazzo, Andrea Ruzzenenti
* CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
*/

#include <yarp/math/FrameTransform.h>

#include <cstdio>

std::string yarp::math::FrameTransform::toString()
{
    char buff[1024];
    sprintf(buff, "%s -> %s \n tran: %f %f %f \n rot: %f %f %f %f \n\n",
                  src_frame_id.c_str(),
                  dst_frame_id.c_str(),
                  translation.tX,
                  translation.tY,
                  translation.tZ,
                  rotation.x(),
                  rotation.y(),
                  rotation.z(),
                  rotation.w());
    return std::string(buff);
}
