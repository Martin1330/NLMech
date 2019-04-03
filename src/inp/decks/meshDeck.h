// Copyright (c) 2019    Prashant K. Jha
//
// Distributed under the GNU GENERAL PUBLIC LICENSE, Version 3.0.
// (See accompanying file LICENSE.txt)

#ifndef INP_MESHDECK_H
#define INP_MESHDECK_H

#include <string>

namespace inp {

/**
 * \ingroup Input
 */
/**@{*/

/*! @brief Structure to read and store mesh related input data */
struct MeshDeck {

  /**
   * @name Data members
   */
  /**@{*/

  /*! @brief Dimension */
  size_t d_dim;

  /*!
   * @brief Tag for spatial discretization
   *
   * List of allowed values are:
   * - \a finite_difference
   * - \a weak_finite_element
   * - \a nodal_finite_element
   * - \a truss_finite_element
   */
  std::string d_spatialDiscretization;

  /*! @brief Filename to read mesh data */
  std::string d_filename;

  /** @}*/

  /*!
   * @brief Constructor
   */
  MeshDeck() : d_dim(0){};
};

/** @}*/

} // namespace inp

#endif // INP_MESHDECK_H
