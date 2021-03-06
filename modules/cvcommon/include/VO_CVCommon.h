/****************************************************************************************************
*                                                                                                   *
*                   IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.               *
*                                                                                                   *
*   By downloading, copying, installing or using the software you agree to this license.            *
*   If you do not agree to this license, do not download, install, copy or use the software.        *
*                                                                                                   *
*                                   License Agreement                                               *
*                           For Vision Open Statistical Models                                      *
*                                                                                                   *
* Copyright (C):    2006~2014 by JIA Pei, all rights reserved.                                      *
*                                                                                                   *
*                   VOSM is free software under the terms of the GNU Lesser General Public License  *
*                   (GNU LGPL) as published by the Free Software Foundation; either version 3.0 of  *
*                   the License, or (at your option) any later version.                             *
*                   You can use it, modify it, redistribute it, etc; and redistribution and use in  *
*                   source and binary forms, with or without modification, are permitted provided   *
*                   that the following conditions are met:                                          *
*                                                                                                   *
*                   a) Redistribution's of source code must retain this whole paragraph of          *
*                   copyright notice, including this list of conditions and all the following       *
*                   contents in this copyright paragraph.                                           *
*                                                                                                   *
*                   b) Redistribution's in binary form must reproduce this whole paragraph of       *
*                   copyright notice, including this list of conditions and all the following       *
*                   contents in this copyright paragraph, and/or other materials provided with      *
*                   the distribution.                                                               *
*                                                                                                   *
*                   c) The name of the copyright holders may not be used to endorse or promote      *
*                   products derived from this software without specific prior written permission.  *
*                                                                                                   *
*                   Any publications based on this code must cite the following five papers,        *
*                   technic reports and on-line materials.                                          *
*                                                                                                   *
*                   1) P. JIA, 2D Statistical Models, Technical Report of Vision Open Working       *
*                   Group, 2st Edition, Oct 21, 2010.                                               *
*                   http://www.visionopen.com/members/jiapei/publications/pei_sm2dreport2010.pdf    *
*                                                                                                   *
*                   2) P. JIA. Audio-visual based HMI for an Intelligent Wheelchair.                *
*                   PhD thesis, University of Essex, 2010.                                          *
*                   http://www.visionopen.com/members/jiapei/publications/pei_thesischapter34.pdf   *
*                                                                                                   *
*                   3) T. Cootes and C. Taylor. Statistical models of appearance for computer       *
*                   vision. Technical report, Imaging Science and Biomedical Engineering,           *
*                   University of Manchester, March 8 2004.                                         *
*                                                                                                   *
*                   4) I. Matthews and S. Baker. Active appearance models revisited.                *
*                   International Journal of Computer Vision, 60(2):135–164, November 2004.         *
*                                                                                                   *
*                   5) M. B. Stegmann, Active Appearance Models: Theory, Extensions and Cases,      *
*                   http://www2.imm.dtu.dk/~aam/main/, 2000.                                        *
*                                                                                                   *
*                                                                                                   *
* Version:          0.3.4                                                                           *
* Author:           JIA Pei                                                                         *
* Contact:          jp4work@gmail.com                                                               *
* URL:              http://www.visionopen.com                                                       *
* Create Date:      2010-02-06                                                                      *
* Modify Date:      2014-04-16                                                                      *
****************************************************************************************************/


#ifndef __VO_CVCOMMON_H__
#define __VO_CVCOMMON_H__


#include "opencv/cxcore.h"
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "VO_Common.h"
#include "VO_BoostCommon.h"


/// Common colors
static cv::Scalar colors[] =
{
    cv::Scalar(0,0,255),        // red
    cv::Scalar(255,0,0),        // blue
    cv::Scalar(0,255,0),        // green
    cv::Scalar(0,255,255),      // yellow
    cv::Scalar(255,255,0),      // cyan
    cv::Scalar(255,0,255),      // magenta
    cv::Scalar(0,0,0),          // black
    cv::Scalar(255,255,255),    // white
    cv::Scalar(0,128,255),      //
    cv::Scalar(255,128,0),      //
    cv::Scalar(0,255,128)       //
};


/** output every element of a cv::Mat */
static std::ostream& operator<< ( std::ostream& os, const cv::Mat& mat )
{
    unsigned int channels = mat.channels();
    unsigned int depth = mat.depth();
    if (!(channels == 1 || channels == 3))
    {
        std::cerr << "Cannot deal with images with nChannels != 1 or 3." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if(channels == 1)
    {
        switch( depth )
        {
            case CV_8U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<unsigned char>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_8S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<char>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_16U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<unsigned short>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_16S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<short>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_32S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<int>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_32F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<float>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_64F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<double>(i, j) << " ";
                    }
                    os << std::endl;
                }
            }
            break;
        }
    }
    else if (channels == 3)
    {
        switch( depth )
        {
            case CV_8U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<cv::Vec3b>(i, j)[0] << " "
                            << mat.at<cv::Vec3b>(i, j)[1] << " "
                            << mat.at<cv::Vec3b>(i, j)[2] << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_16S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<cv::Vec3s>(i, j)[0] << " "
                            << mat.at<cv::Vec3s>(i, j)[1] << " "
                            << mat.at<cv::Vec3s>(i, j)[2] << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_32S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<cv::Vec3i>(i, j)[0] << " "
                            << mat.at<cv::Vec3i>(i, j)[1] << " "
                            << mat.at<cv::Vec3i>(i, j)[2] << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_32F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<cv::Vec3f>(i, j)[0] << " "
                            << mat.at<cv::Vec3f>(i, j)[1] << " "
                            << mat.at<cv::Vec3f>(i, j)[2] << " ";
                    }
                    os << std::endl;
                }
            }
            break;
            case CV_64F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        os << mat.at<cv::Vec3d>(i, j)[0] << " "
                            << mat.at<cv::Vec3d>(i, j)[1] << " "
                            << mat.at<cv::Vec3d>(i, j)[2] << " ";
                    }
                    os << std::endl;
                }
            }
            break;
        }
    }

    return os;
}


/** input every element to a cv::Mat */
static std::istream& operator>> ( std::istream& is, cv::Mat& mat )
{
    unsigned int channels = mat.channels();
    unsigned int depth = mat.depth();
    if (!(channels == 1 || channels == 3))
    {
        std::cerr << "Cannot deal with images with nChannels != 1 or 3." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    if(channels == 1)
    {
        switch( depth )
        {
            case CV_8U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<unsigned char>(i, j);
                    }
                }
            }
            break;
            case CV_8S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<char>(i, j);
                    }
                }
            }
            break;
            case CV_16U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<unsigned short>(i, j);
                    }
                }
            }
            break;
            case CV_16S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<short>(i, j);
                    }
                }
            }
            break;
            case CV_32S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<int>(i, j);
                    }
                }
            }
            break;
            case CV_32F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<float>(i, j);
                    }
                }
            }
            break;
            case CV_64F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<double>(i, j);
                    }
                }
            }
            break;
        }
    }
    
    else if (channels == 3)
    {
        switch( mat.depth() )
        {
            case CV_8U:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<cv::Vec3b>(i, j)[0]
                            >> mat.at<cv::Vec3b>(i, j)[1]
                            >> mat.at<cv::Vec3b>(i, j)[2];
                    }
                }
            }
            break;
            case CV_16S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<cv::Vec3s>(i, j)[0]
                            >> mat.at<cv::Vec3s>(i, j)[1]
                            >> mat.at<cv::Vec3s>(i, j)[2];
                    }
                }
            }
            break;
            case CV_32S:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<cv::Vec3i>(i, j)[0]
                            >> mat.at<cv::Vec3i>(i, j)[1]
                            >> mat.at<cv::Vec3i>(i, j)[2];
                    }
                }
            }
            break;
            case CV_32F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<cv::Vec3f>(i, j)[0]
                            >> mat.at<cv::Vec3f>(i, j)[1]
                            >> mat.at<cv::Vec3f>(i, j)[2];
                    }
                }
            }
            break;
            case CV_64F:
            {
                for ( unsigned int i = 0; i < mat.rows; i++ )
                {
                    for ( unsigned int j = 0; j < mat.cols; j++ )
                    {
                        is >> mat.at<cv::Vec3d>(i, j)[0]
                            >> mat.at<cv::Vec3d>(i, j)[1]
                            >> mat.at<cv::Vec3d>(i, j)[2];
                    }
                }
            }
            break;
        }
    }

    return is;
}


/** output every element of a cv::Mat_<T> */
template <class T>
static std::ostream& operator<< ( std::ostream& os, const cv::Mat_<T>& mat )
{
    for ( unsigned int i = 0; i < mat.rows; i++ )
    {
        for ( unsigned int j = 0; j < mat.cols; j++ )
        {
            os << mat(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}


/** input every element to a cv::Mat_<T> */
template <class T>
static std::istream& operator>> ( std::istream& is, cv::Mat_<T>& mat )
{
    for ( unsigned int i = 0; i < mat.rows; i++ )
    {
        for ( unsigned int j = 0; j < mat.cols; j++ )
        {
            is >> mat(i, j);
        }
    }
    return is;
}


/** output a cv::Rect */
static std::ostream& operator<< ( std::ostream& os, const cv::Rect& rect )
{
    os << rect.x << " " << rect.y << " " << 
            rect.width << " " << rect.height << std::endl;
    return os;
}


/** output a cv::Point */
static std::ostream& operator<< ( std::ostream &os, const cv::Point& pt )
{
    os << pt.x << " " << pt.y << std::endl;
    return os;
}

/** output a cv::Point2f */
static std::ostream& operator<< ( std::ostream &os, const cv::Point2f& pt )
{
    os << pt.x << " " << pt.y << std::endl;
    return os;
}



/** Size compare */
static int cvSizeCompare( const void *arg1, const void *arg2 )
{
    return ( (*(cv::Size*)arg1).width * (*(cv::Size*)arg1).height -
            (*(cv::Size*)arg2).width * (*(cv::Size*)arg2).height );
}


/** cv::Rect compare */
static int cvRectCompare( const void *arg1, const void *arg2 )
{
    return ( (*(cv::Size*)arg1).width * (*(cv::Size*)arg1).height -
            (*(cv::Size*)arg2).width * (*(cv::Size*)arg2).height );
}



/** Image clamp */
template<class T>
static void clamp ( const cv::Mat& iImg, cv::Mat& oImg, T low, T up )
{
    if(low < up)
    {
        std::cerr << "lower bound is smaller than upper bound!" << std::endl;
        exit(1);
    }
    
    unsigned int NbOfDepth = iImg.depth();
    unsigned int NbOfChannels = iImg.channels();
    
    if(NbOfChannels == 1)
    {
        switch(NbOfDepth)
        {
            case CV_8U:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<uchar>(y,x) < (uchar) low )
                            oImg.at<uchar>(y,x) = (uchar) low;
                        else if( iImg.at<uchar>(y,x) > (uchar) up )
                            oImg.at<uchar>(y,x) = (uchar) up;
                        else
                            oImg.at<uchar>(y,x) = iImg.at<uchar>(y,x);
                    }
                }
            }
            break;
            case CV_8S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<char>(y,x) < (char) low )
                            oImg.at<char>(y,x) = (char) low;
                        else if( iImg.at<char>(y,x) > (char) up )
                            oImg.at<char>(y,x) = (char) up;
                        else
                            oImg.at<char>(y,x) = iImg.at<char>(y,x);
                    }
                }
            }
            break;
            case CV_16U:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<unsigned short>(y,x) < (unsigned short) low )
                            oImg.at<unsigned short>(y,x) = (unsigned short) low;
                        else if( iImg.at<unsigned short>(y,x) > (unsigned short) up )
                            oImg.at<unsigned short>(y,x) = (unsigned short) up;
                        else
                            oImg.at<unsigned short>(y,x) = iImg.at<unsigned short>(y,x);
                    }
                }
            }
            break;
            case CV_16S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<short>(y,x) < (short) low )
                            oImg.at<short>(y,x) = (short) low;
                        else if( iImg.at<short>(y,x) > (short) up )
                            oImg.at<short>(y,x) = (short) up;
                        else
                            oImg.at<short>(y,x) = iImg.at<short>(y,x);
                    }
                }
            }
            break;    
            case CV_32S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<int>(y,x) < (int) low )
                            oImg.at<int>(y,x) = (int) low;
                        else if( iImg.at<int>(y,x) > (int) up )
                            oImg.at<int>(y,x) = (int) up;
                        else
                            oImg.at<int>(y,x) = iImg.at<int>(y,x);
                    }
                }
            }
            break;
            case CV_32F:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<float>(y,x) < (float) low )
                            oImg.at<float>(y,x) = (float) low;
                        else if( iImg.at<float>(y,x) > (float) up )
                            oImg.at<float>(y,x) = (float) up;
                        else
                            oImg.at<float>(y,x) = iImg.at<float>(y,x);
                    }
                }
            }
            break;
            case CV_64F:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        if( iImg.at<double>(y,x) < (double) low )
                            oImg.at<double>(y,x) = (double) low;
                        else if( iImg.at<double>(y,x) > (double) up )
                            oImg.at<double>(y,x) = (double) up;
                        else
                            oImg.at<double>(y,x) = iImg.at<double>(y,x);
                    }
                }
            }
            break;
            default:
            break;
        }
    }
    else if(NbOfChannels == 3)
    {
        for(unsigned int chan = 0; chan < NbOfChannels; chan++)
        {
            switch(NbOfDepth)
            {
                case CV_8U:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3b>(y,x)[chan] < (uchar) low )
                                oImg.at<cv::Vec3b>(y,x)[chan] = (uchar) low;
                            else if( iImg.at<cv::Vec3b>(y,x)[chan] > (uchar) up )
                                oImg.at<cv::Vec3b>(y,x)[chan] = (uchar) up;
                            else
                                oImg.at<cv::Vec3b>(y,x)[chan] = iImg.at<cv::Vec3b>(y,x)[chan];
                        }
                    }
                }
                break;
                //case CV_8S:
                //    {
                //        for(unsigned int x = 0; x < iImg.rows; x++)
                //        {
                //            for(unsigned int y = 0; y < iImg.cols; y++)
                //            {
                //                if( iImg.at<cv::Vec3s>(y,x)[chan] < (char) low )
                //                    oImg.at<cv::Vec3s>(y,x)[chan] = (char) low;
                //                else if( iImg.at<cv::Vec3s>(y,x)[chan] > (char) up )
                //                    oImg.at<cv::Vec3s>(y,x)[chan] = (char) up;
                //                else
                //                    oImg.at<cv::Vec3s>(y,x)[chan] = iImg.at<cv::Vec3s>(y,x)[chan];
                //            }
                //        }
                //    }
                //    break;
                case CV_16U:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3w>(y,x)[chan] < (unsigned short) low )
                                oImg.at<cv::Vec3w>(y,x)[chan] = (unsigned short) low;
                            else if( iImg.at<cv::Vec3w>(y,x)[chan] > (unsigned short) up )
                                oImg.at<cv::Vec3w>(y,x)[chan] = (unsigned short) up;
                            else
                                oImg.at<cv::Vec3w>(y,x)[chan] = iImg.at<cv::Vec3w>(y,x)[chan];
                        }
                    }
                }
                break;
                case CV_16S:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3s>(y,x)[chan] < (short) low )
                                oImg.at<cv::Vec3s>(y,x)[chan] = (short) low;
                            else if( iImg.at<cv::Vec3s>(y,x)[chan] > (short) up )
                                oImg.at<cv::Vec3s>(y,x)[chan] = (short) up;
                            else
                                oImg.at<cv::Vec3s>(y,x)[chan] = iImg.at<cv::Vec3s>(y,x)[chan];
                        }
                    }
                }
                break;    
                case CV_32S:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3i>(y,x)[chan] < (int) low )
                                oImg.at<cv::Vec3i>(y,x)[chan] = (int) low;
                            else if( iImg.at<cv::Vec3i>(y,x)[chan] > (int) up )
                                oImg.at<cv::Vec3i>(y,x)[chan] = (int) up;
                            else
                                oImg.at<cv::Vec3i>(y,x)[chan] = iImg.at<cv::Vec3i>(y,x)[chan];
                        }
                    }
                }
                break;
                case CV_32F:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3f>(y,x)[chan] < (float) low )
                                oImg.at<cv::Vec3f>(y,x)[chan] = (float) low;
                            else if( iImg.at<cv::Vec3f>(y,x)[chan] > (float) up )
                                oImg.at<cv::Vec3f>(y,x)[chan] = (float) up;
                            else
                                oImg.at<cv::Vec3f>(y,x)[chan] = iImg.at<cv::Vec3f>(y,x)[chan];
                        }
                    }
                }
                break;
                case CV_64F:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            if( iImg.at<cv::Vec3d>(y,x)[chan] < (double) low )
                                oImg.at<cv::Vec3d>(y,x)[chan] = (double) low;
                            else if( iImg.at<cv::Vec3d>(y,x)[chan] > (double) up )
                                oImg.at<cv::Vec3d>(y,x)[chan] = (double) up;
                            else
                                oImg.at<cv::Vec3d>(y,x)[chan] = iImg.at<cv::Vec3d>(y,x)[chan];
                        }
                    }
                }
                break;
                default:
                break;
            }
        }
    }
}


/** Image strech */
template<class T>
static void strech ( const cv::Mat& iImg, cv::Mat& oImg, T low, T up )
{
    if(low < up)
    {
        std::cerr << "lower bound is smaller than upper bound!" << std::endl;
        exit(1);
    }

    unsigned int NbOfDepth = iImg.depth();
    unsigned int NbOfChannels = iImg.channels();
    
    if(NbOfChannels == 1)
    {
        double minVal = 0.0, maxVal = 0.0, diff = 0.0, temp = 0.0;
        cv::minMaxLoc(iImg, &minVal, &maxVal);
        diff = maxVal - minVal;
        
        if(diff <= FLT_EPSILON)
        {
            oImg = cv::Mat::zeros(iImg.size(), iImg.type());
            return;
        }

        switch(NbOfDepth)
        {
            case CV_8U:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<uchar>(y,x);
                        oImg.at<uchar>(y,x) = (uchar)( (temp - minVal)/
                            diff*(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            case CV_8S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<char>(y,x);
                        oImg.at<char>(y,x) = (char)( (temp - minVal)/
                            diff*(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            case CV_16U:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<unsigned short>(y,x);
                        oImg.at<unsigned short>(y,x) = 
                            (unsigned short)( (temp - minVal)/
                            diff*(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            case CV_16S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<short>(y,x);
                        oImg.at<short>(y,x) = (short)( (temp - minVal)/diff
                            *(double)(up-low)+(double)low );
                    }
                }
            }
            break;    
            case CV_32S:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<int>(y,x);
                        oImg.at<int>(y,x) = (int)( (temp - minVal)/diff
                            *(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            case CV_32F:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<float>(y,x);
                        oImg.at<float>(y,x) = (float)( (temp - minVal)/diff
                            *(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            case CV_64F:
            {
                for(unsigned int x = 0; x < iImg.rows; x++)
                {
                    for(unsigned int y = 0; y < iImg.cols; y++)
                    {
                        temp = (double)iImg.at<double>(y,x);
                        oImg.at<double>(y,x) = (double)( (temp - minVal)/diff
                            *(double)(up-low)+(double)low );
                    }
                }
            }
            break;
            default:
            break;
        }
    }
    else if(NbOfChannels == 3)
    {
        double  minVal_b = 0.0, maxVal_b = 0.0, 
                minVal_g = 0.0, maxVal_g = 0.0, 
                minVal_r = 0.0, maxVal_r = 0.0, 
                minVal = 0.0, maxVal = 0.0,
                diff = 0.0, temp = 0.0;
        std::vector<cv::Mat> bgr;
        cv::split(iImg, bgr);

        cv::minMaxLoc(bgr[0], &minVal_b, &maxVal_b);
        cv::minMaxLoc(bgr[1], &minVal_g, &maxVal_g);
        cv::minMaxLoc(bgr[2], &minVal_r, &maxVal_r);
        minVal = cv::min(cv::min(minVal_b, minVal_g), minVal_r);
        maxVal = cv::max(cv::max(maxVal_b, maxVal_g), maxVal_r);
        diff = maxVal - minVal;
        
        if(diff <= FLT_EPSILON)
        {
            oImg = cv::Mat::zeros(iImg.size(), iImg.type());
            return;
        }
        
        for(unsigned int chan = 0; chan < NbOfChannels; chan++)
        {
            switch(NbOfDepth)
            {
                case CV_8U:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3b>(y,x)[chan];
                            oImg.at<cv::Vec3b>(y,x)[chan] = (uchar)( (temp - minVal)
                                /diff*(double)(up-low)+(double)low );
                        }
                    }
                }
                break;
//                case CV_8S:
//                {
//                    for(unsigned int x = 0; x < iImg.rows; x++)
//                    {
//                        for(unsigned int y = 0; y < iImg.cols; y++)
//                        {
//                            if( iImg.at<cv::Vec3s>(y,x)[chan] < (char) low )
//                                oImg.at<cv::Vec3s>(y,x)[chan] = (char) low;
//                            else if( iImg.at<cv::Vec3s>(y,x)[chan] > (char) up )
//                                oImg.at<cv::Vec3s>(y,x)[chan] = (char) up;
//                            else
//                                oImg.at<cv::Vec3s>(y,x)[chan] = iImg.at<cv::Vec3s>(y,x)[chan];
//                        }
//                    }
//                }
//                break;
                case CV_16U:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3w>(y,x)[chan];
                            oImg.at<cv::Vec3w>(y,x)[chan] = 
                                (unsigned short)( (temp - minVal)/diff
                                *(double)(up-low)+(double)low );
                        }
                    }
                }
                break;
                case CV_16S:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3s>(y,x)[chan];
                            oImg.at<cv::Vec3s>(y,x)[chan] = 
                                (short)( (temp - minVal)/diff
                                *(double)(up-low)+(double)low );
                        }
                    }
                }
                break;    
                case CV_32S:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3i>(y,x)[chan];
                            oImg.at<cv::Vec3i>(y,x)[chan] = 
                                (int)( (temp - minVal)/diff
                                *(double)(up-low)+(double)low );
                        }
                    }
                }
                break;
                case CV_32F:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3f>(y,x)[chan];
                            oImg.at<cv::Vec3f>(y,x)[chan] = 
                                (float)( (temp - minVal)/diff
                                *(double)(up-low)+(double)low );
                        }
                    }
                }
                break;
                case CV_64F:
                {
                    for(unsigned int x = 0; x < iImg.rows; x++)
                    {
                        for(unsigned int y = 0; y < iImg.cols; y++)
                        {
                            temp = (double)iImg.at<cv::Vec3d>(y,x)[chan];
                            oImg.at<cv::Vec3d>(y,x)[chan] = 
                                (double)( (temp - minVal)/diff
                                *(double)(up-low)+(double)low );
                        }
                    }
                }
                break;
                default:
                break;
            }
        }
    }
}


/** cv::Point2f division */
template<class T>
static cv::Point2f operator / ( const cv::Point2f& pt, T t)
{
    if (fabs((float)t) < FLT_MIN)
    {
        std::cerr << "divided by zero" << std::endl;
        exit(0);
    }
    cv::Point2f res;
    res.x = pt.x / t;
    res.y = pt.y / t;
    return res;
}


/** cv::Point2f add */
static cv::Point2f operator+ ( const cv::Point2f& pt1, const cv::Point2f& pt2 )
{
    cv::Point2f res;
    res.x = pt1.x + pt2.x;
    res.y = pt1.y + pt2.y;
    return res;
}


/** cv::Point2f subtraction */
static cv::Point2f operator- ( const cv::Point2f& pt1, const cv::Point2f& pt2 )
{
    cv::Point2f res;
    res.x = pt1.x - pt2.x;
    res.y = pt1.y - pt2.y;
    return res;
}


/** cv::Point2f multiplication */
template <class T>
static cv::Rect operator* ( const cv::Rect& rect1, T value )
{
    cv::Rect res;
    res.x = rect1.x * value;
    res.y = rect1.y * value;
    res.width = rect1.width * value;
    res.height = rect1.height * value;
    return res;
}


/**
 * @Ref    http://www.newton.dep.anl.gov/newton/askasci/1995/math/MATH061.HTM
 *        abs(Ar + Bs + C)/sqrt(A^2 + B^2)
*/
static float cvDistFromAPoint2ALine2D(  const cv::Point2f& pt,
                                        const std::vector<float>& lp)
{
    return ( fabs(lp[0]*pt.x+lp[1]*pt.y+lp[2]) / 
        sqrt(lp[0]*lp[0]+lp[1]*lp[1]) );
}


/**
* @brief    Save all images in sequence in a specific folder
* @param    imgs        -- Input        the source images
* @param    fdname      -- Input        the specific folder
* @ref      OpenCV 2.x documentation
 */
static void SaveSequentialImagesInFolder(   const std::vector<cv::Mat>& imgs,
                                            const std::string& fdname)
{
    if (!boost::filesystem::is_directory(fdname) )
        boost::filesystem::create_directory( fdname );

    std::stringstream ssi;
    std::string stri;
    std::string filename;
    unsigned int NbOfImages = imgs.size();
    for(unsigned int i = 0; i < NbOfImages; i++)
    {
        ssi << i;
        ssi >> stri;
        if(stri.length() == 1)
            filename = fdname + "/0" + stri + ".jpg";
        else if(stri.length() == 2)
            filename = fdname + "/" + stri + ".jpg";
        imwrite(filename.c_str(), imgs[i] );
        ssi.clear();
    }
}


/**
 * @brief    convolve using DFT.
 * @param    A    -- Input    the source image
 * @param    B    -- Input    the filtering template
 * @param    C    -- Output    the convoluted image, must of the same size as A
 * @ref      OpenCV 2.x documentation
 */
static void convolveDFT(const cv::Mat& A, const cv::Mat& B, cv::Mat& C)
{
    // reallocate the output array if needed
    //    cv::Mat C(A.rows + B.rows - 1, A.cols + B.cols - 1, A.type());
    cv::Size dftSize;
    // compute the size of DFT transform
    dftSize.width = cv::getOptimalDFTSize(A.cols + B.cols - 1);
    dftSize.height = cv::getOptimalDFTSize(A.rows + B.rows - 1);
    // allocate temporary buffers and initialize them with 0’s
    cv::Mat tempA(dftSize, A.type(), cv::Scalar::all(0));
    cv::Mat tempB(dftSize, B.type(), cv::Scalar::all(0));
    // copy A and B to the top-left corners of tempA and tempB, respectively
    cv::Mat roiA(tempA, cv::Rect(0,0,A.cols,A.rows));
    A.copyTo(roiA);
    cv::Mat roiB(tempB, cv::Rect(0,0,B.cols,B.rows));
    B.copyTo(roiB);
    // now transform the padded A & B in-place;
    // use "nonzeroRows" hint for faster processing
    cv::dft(tempA, tempA, 0, A.rows);
    cv::dft(tempB, tempB, 0, B.rows);
    // multiply the spectrums;
    // the function handles packed spectrum representations well
    cv::mulSpectrums(tempA, tempB, tempA, 0);
    // transform the product back from the frequency domain.
    // Even though all the result rows will be non-zero,
    // we need only the first C.rows of them, and thus we
    // pass nonzeroRows == C.rows
    cv::dft(tempA, tempA, cv::DFT_INVERSE + cv::DFT_SCALE, A.rows + B.rows - 1);
    // now copy the result back to C.
    //    tempA(cv::Rect(0, 0, C.cols, C.rows)).copyTo(C);
    tempA(cv::Rect(B.cols/2, B.rows/2, A.cols, A.rows)).copyTo(C);
    // all the temporary buffers will be deallocated automatically
}

#endif    // __VO_CVCOMMON_H__

