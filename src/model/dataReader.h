#ifndef DATA_READER_H
#define DATA_READER_H


// Achab
#include <model/projectProperties.h>

// C++
#include <fstream>
#include <iostream>

// Qt
#include <qdebug.h>
#include <QtCore/qstring.h>



class DataReader
{

//---------------------------------------------------------------------------------------
// PUBLIC MEMBER FUNCTION
public:

    /// @brief Default constructor.
	DataReader() noexcept;



    /// @brief Destructor.
    ~DataReader() = default;



    /// @brief
    ///
    /// @param time: the number of the frame.
    /// @param component_name: the mobdec component name
    /// @param project_properties:
    static void readFeaturePointFile(uint time,
    								 QString component_name,
									 const ProjectProperties& project_properties) noexcept;

};

#endif /* DATA_READER_H */
