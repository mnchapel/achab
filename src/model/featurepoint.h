#ifndef FEATURE_POINT_H
#define FEATURE_POINT_H



// Achab
#include <model/constant.h>
#include <model/labeling.h>

// C++
#include <array>

// Opencv
#include <opencv2/core.hpp>

// Qt
#include <qpoint.h>



class FeaturePoint{

//-----------------------------------------------------------------------------
// PROTECTED MEMBER DATA
protected:

    ///
    uint age;

    ///
    double confidence_value;

    ///
    double distance_to_camera;

    ///
    char label;

    ///
    double x;

    ///
    double y;


//-----------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
    FeaturePoint() noexcept;



    /// @brief Constructor.
    FeaturePoint(double x
    			,double y) noexcept;



    /// @brief Destructor.
    ~FeaturePoint() noexcept = default;



    /// @brief
    ///
    /// @param feature_point
    ///
    /// @return
    double distance2DToFeaturePoint(FeaturePoint& feature_point) const noexcept;



    /// @brief
    ///
    /// @param point
    ///
    /// @return
    double distance2DToQPointF(QPointF& point) const noexcept;



    /// @brief
    ///
    /// @return
    double getConfidenceValue() const noexcept;



    /// @brief
    ///
    /// @return
    double getLabel() const noexcept;



    /// @brief
    ///
    /// @return
    double getX() const noexcept;



    /// @brief
    ///
    /// @return
    double getY() const noexcept;



    /// @brief
    ///
    /// @param confidence_value
    void setConfidenceValue(double confidence_value) noexcept;



    /// @brief
    ///
    /// @param label
    void setLabel(double label) noexcept;



    /// @brief
    ///
    /// @param x
    void setX(double x) noexcept;



    /// @brief
    ///
    /// @param y
    void setY(double y) noexcept;

};

#endif
