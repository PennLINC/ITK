/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    itkHypersphereKernelMeanShiftModeSeeker.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#ifndef __itkHypersphereKernelMeanShiftModeSeeker_h
#define __itkHypersphereKernelMeanShiftModeSeeker_h

#include "itkMeanShiftModeSeekerBase.h"

#include "itkFixedArray.h"
#include "itkNumericTraits.h"

namespace itk{ 
namespace Statistics{

/** \class HypersphereKernelMeanShiftModeSeeker
 * \brief Evolves the mode using a hyperspherical kernel defined by a
 * radius (which is set by SetRadius) method.
 *
 * \sa MeanShiftModeSeekerBase 
 */

template< class TSample >
class HypersphereKernelMeanShiftModeSeeker :
    public MeanShiftModeSeekerBase< TSample >
{
public:
  /** Standard class typedefs. */
  typedef HypersphereKernelMeanShiftModeSeeker Self;
  typedef MeanShiftModeSeekerBase< TSample > Superclass ;
  typedef SmartPointer<Self> Pointer;

  /** Standard Macros */
  itkTypeMacro(HypersphereKernelMeanShiftModeSeeker, 
               MeanShiftModeSeekerBase);
  itkNewMacro(Self) ;
  
  /** Typedefs from the superclass */
  typedef typename Superclass::MeasurementVectorType MeasurementVectorType ;
  typedef typename Superclass::SearchResultVectorType SearchResultVectorType ;
  typedef typename Superclass::MeasurementType MeasurementType ;

  /** Size of a measurement vector */
  itkStaticConstMacro( MeasurementVectorSize, unsigned int,
                       MeasurementVectorType::Length ) ;

  /** Type for the sum of measurements */
  typedef double RealMeasurementType ;

  /** Type fot the sum of measurement vectors used in computing the new
    * mode */
  typedef FixedArray< RealMeasurementType,
                      itkGetStaticConstMacro( MeasurementVectorSize ) > 
  MeasurementVectorSumType ;

  /** Sets the radius of the kernel */
  void SetSearchRadius(double radius) ;
  
  /** Gets the radius of the kernel  */
  double GetSearchRadius()
  { return m_SearchRadius ; }

  /** Returns the covariance matrix of the target sample data */ 
  MeasurementVectorType Evolve(MeasurementVectorType instance) ;
  
protected:
  HypersphereKernelMeanShiftModeSeeker() ;
  virtual ~HypersphereKernelMeanShiftModeSeeker() ;
  void PrintSelf(std::ostream& os, Indent indent) const;

  /** Computes the new mode with the given query point (queryPoint). The
    * new mode will be stored in the newPoint */ 
  inline void ComputeMode(MeasurementVectorType queryPoint,
                          MeasurementVectorType& newPoint) ;

private:
  /** Radius of the kernel */
  double m_SearchRadius ;

  /** Temporary measurement vector sum: internal use */ 
  MeasurementVectorSumType m_TempVectorSum ;
  
  /** Temporary measurement vector: internal use */
  MeasurementVectorType m_TempVector ;
} ; // end of class
    
} // end of namespace Statistics 
} // end of namespace itk 

#ifndef ITK_MANUAL_INSTANTIATION
#include "itkHypersphereKernelMeanShiftModeSeeker.txx"
#endif

#endif

