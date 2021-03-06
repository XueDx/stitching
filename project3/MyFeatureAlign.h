///////////////////////////////////////////////////////////////////////////
//
// NAME
//  FeatureAlign.h -- image registration using feature matching
//
// SPECIFICATION
//  int alignPair(const FeatureSet &f1, const FeatureSet &f2, const vector<FeatureMatch> &matches, MotionModel m, float f, int width, int height, int nRANSAC, double RANSACthresh, CTransform3x3& M);
//
// PARAMETERS
//  f1, f2              source feature sets
//  matches				correspondences between f1 and f2
//  m                   motion model
//  f                   focal length
//  width               image width
//  height              image height
//  nRANSAC             number of RANSAC iterations
//  RANSACthresh        RANSAC distance threshold
//  M                   transformation matrix (output)
//
// DESCRIPTION
//  These routines compute the alignment between two images using
//  feature-based motion estimation.  The features and their
//  correspondences have already been computed.
//
// SEE ALSO
//  FeatureAlign.cpp    implementation
//
// Copyright ?Richard Szeliski, 2001.  See Copyright.h for more details
//
///////////////////////////////////////////////////////////////////////////
#pragma once
#include "FeatureSet.h"
#include "FeatureAlign.h"

// Compute transformation between two images.
vector<int> MyalignPair(const FeatureSet &f1, const FeatureSet &f2,
					  const vector<FeatureMatch> &matches, MotionModel m,
					  float f, const pair<int,int>& WH1, const pair<int,int>& WH2,
					  int nRANSAC, double RANSACthresh, CTransform3x3& M);

// Count the number of feature matches concurring with transformation.
int MycountInliers(const FeatureSet &f1, const FeatureSet &f2,
				 const vector<FeatureMatch> &matches, MotionModel m,
				 float f, const pair<int,int>& WH1, const pair<int,int>& WH2, 
				 CTransform3x3 M, double RANSACthresh, vector<int> &inliers);

// Compute the least squares optimal transformation from inlier feature
// matches.
int MyleastSquaresFit(const FeatureSet &f1, const FeatureSet &f2,
					const vector<FeatureMatch> &matches, MotionModel m,
					float f, const pair<int,int>& WH1, const pair<int,int>& WH2,
					const vector<int> &inliers, CTransform3x3& M);
