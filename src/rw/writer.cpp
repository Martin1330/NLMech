////////////////////////////////////////////////////////////////////////////////
//  Copyright (c) 2019 Prashant K. Jha
//  Copyright (c) 2019 Patrick Diehl
//
//  Distributed under the Boost Software License, Version 1.0. (See accompanying
//  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
////////////////////////////////////////////////////////////////////////////////

#include "writer.h"
#include "vtkWriter.h"
#include "legacyVtkWriter.h"
#include "mshWriter.h"
#include "inp/input.h"
#include "inp/decks/modelDeck.h"
#include "inp/decks/outputDeck.h"
#include "data/DataManager.h"
#include "fe/mesh.h"
#include "geometry/neighbor.h"

rw::writer::Writer::Writer() :
		d_vtkWriter_p(nullptr), d_legacyVtkWriter_p(nullptr), d_mshWriter_p(
				nullptr), d_format("vtu") {
}

rw::writer::Writer::Writer(const std::string &filename,
                           const std::string &format,
                           const std::string &compress_type)
    : d_vtkWriter_p(nullptr), d_legacyVtkWriter_p(nullptr),
      d_mshWriter_p(nullptr), d_format("vtu") {
  open(filename, format, compress_type);
}


rw::writer::Writer::Writer(const std::string &format,
		const std::string &compress_type) :
		d_vtkWriter_p(nullptr), d_legacyVtkWriter_p(nullptr), d_mshWriter_p(
				nullptr), d_format(format), d_compression_type(compress_type) {

}


rw::writer::Writer::~Writer() {
	delete (d_vtkWriter_p);
}

void rw::writer::Writer::open(const std::string &filename,
                              const std::string &format,
                              const std::string &compress_type) {
  d_format = format;
  if (d_format == "vtu")
    d_vtkWriter_p = new rw::writer::VtkWriter(filename, compress_type);
  else if (d_format == "msh")
    d_mshWriter_p = new rw::writer::MshWriter(filename, compress_type);
  else if (d_format == "legacy_vtk")
    d_legacyVtkWriter_p =
        new rw::writer::LegacyVtkWriter(filename, compress_type);
}

void rw::writer::Writer::appendNodes(const std::vector<util::Point3> *nodes,
		const std::vector<util::Point3> *u) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendNodes(nodes, u);
	else if (d_format == "msh")
		d_mshWriter_p->appendNodes(nodes, u);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendNodes(nodes, u);
}

void rw::writer::Writer::appendMesh(const std::vector<util::Point3> *nodes,
		const size_t &element_type, const std::vector<size_t> *en_con,
		const std::vector<util::Point3> *u) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendMesh(nodes, element_type, en_con, u);
	else if (d_format == "msh")
		d_mshWriter_p->appendMesh(nodes, element_type, en_con, u);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendMesh(nodes, element_type, en_con, u);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<uint8_t> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<size_t> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<int> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<float> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<double> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<util::Point3> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
		const std::vector<util::SymMatrix3> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);
}

void rw::writer::Writer::appendPointData(const std::string &name,
                       const std::vector<util::Matrix33> *data){

	if (d_format == "vtu")
		d_vtkWriter_p->appendPointData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendPointData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendPointData(name, data);

}

void rw::writer::Writer::appendCellData(const std::string &name,
		const std::vector<float> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendCellData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendCellData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendCellData(name, data);
}

void rw::writer::Writer::appendCellData(const std::string &name,
		const std::vector<util::SymMatrix3> *data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendCellData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendCellData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendCellData(name, data);
}

void rw::writer::Writer::addTimeStep(const double &timestep) {

	if (d_format == "vtu")
		d_vtkWriter_p->addTimeStep(timestep);
	else if (d_format == "msh")
		d_mshWriter_p->addTimeStep(timestep);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->addTimeStep(timestep);
}

void rw::writer::Writer::appendFieldData(const std::string &name,
		const double &data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendFieldData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendFieldData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendFieldData(name, data);
}

void rw::writer::Writer::appendFieldData(const std::string &name,
		const float &data) {

	if (d_format == "vtu")
		d_vtkWriter_p->appendFieldData(name, data);
	else if (d_format == "msh")
		d_mshWriter_p->appendFieldData(name, data);
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->appendFieldData(name, data);
}


void rw::writer::Writer::close() {

	if (d_format == "vtu")
		d_vtkWriter_p->close();
	else if (d_format == "msh")
		d_mshWriter_p->close();
	else if (d_format == "legacy_vtk")
		d_legacyVtkWriter_p->close();
}

void rw::writer::Writer::write(inp::Input *deck, data::DataManager *dataManager,
		size_t d_n, double d_time) {

	std::cout << "Output: time step = " << d_n << "\n";

	// write out % completion of simulation at 10% interval

	float p = float(d_n) * 100. / deck->getModelDeck()->d_Nt;
	int m = std::max(1, int(deck->getModelDeck()->d_Nt / 10));
	if (d_n % m == 0 && int(p) > 0)
		std::cout << "Message: Simulation " << int(p) << "% complete.\n";

	// filename
	// use smaller dt_out as the tag for files
	size_t dt_out = deck->getOutputDeck()->d_dtOutCriteria;
	std::string filename = deck->getOutputDeck()->d_path + "output_"
			+ std::to_string(d_n / dt_out);

	// Open the output file
	open(filename, d_format, d_compression_type);

	// write mesh
	if (dataManager->getMeshP()->getNumElements() != 0
			&& deck->getOutputDeck()->d_performFEOut)
		appendMesh(dataManager->getMeshP()->getNodesP(),
				dataManager->getMeshP()->getElementType(),
				dataManager->getMeshP()->getElementConnectivitiesP(),
				dataManager->getDisplacementP());
	else
		appendNodes(dataManager->getMeshP()->getNodesP(),
				dataManager->getDisplacementP());

	//
	// major simulation data
	//
	std::string tag = "Displacement";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getDisplacementP());

	tag = "Velocity";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getVelocityP());

	tag = "Force";
	if (deck->getOutputDeck()->isTagInOutput(tag)) {

		std::vector<util::Point3> force(dataManager->getMeshP()->getNumNodes(),
				util::Point3());

		for (size_t i = 0; i < force.size(); i++)
			force[i] = (*dataManager->getForceP())[i]
					* dataManager->getMeshP()->getNodalVolume(i);

		appendPointData(tag, &force);
	}

	tag = "time";
	addTimeStep(d_time);

	//
	// minor simulation data
	//
	/*
	 if (!d_policy_p->enablePostProcessing()) {
	 close();
	 return;
	 }
	 */

	tag = "Force_Density";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getForceP());
	
	 tag = "Strain_Energy";
	 //if (deck->getOutputDeck()->isTagInOutput(tag)
	 //&& d_policy_p->populateData("Model_d_e"))
	 //appendPointData(tag, dataManager->getStrainEnergyP());
	 if (deck->getOutputDeck()->isTagInOutput(tag))
	 appendPointData(tag, dataManager->getStrainEnergyP());

	/*
	 tag = "Work_Done";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_w"))
	 appendPointData(tag, &d_w);
	 */

	tag = "Fixity";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getMeshP()->getFixityP());

	tag = "Node_Volume";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getMeshP()->getNodalVolumeP());

	tag = "Neighbors";
	if (deck->getOutputDeck()->isTagInOutput(tag)){
		std::vector<size_t> amountNeighbors;
		size_t nodes = dataManager->getMeshP()->getNumNodes();
		for (size_t i = 0; i < nodes; i++)
			amountNeighbors.push_back(dataManager->getNeighborP()->getNeighbors(i).size());
		appendPointData(tag, &amountNeighbors);
	}

	tag = "Strain_Tensor";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getStrainTensorP());


	tag = "Stress_Tensor";
	if (deck->getOutputDeck()->isTagInOutput(tag))
		appendPointData(tag, dataManager->getStressTensorP());


	/*
	 tag = "Damage_Phi";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_phi"))
	 appendPointData(tag, &d_phi);

	 tag = "Damage_Z";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_Z"))
	 appendPointData(tag, &d_Z);

	 tag = "Fracture_Perienergy_Bond";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_eFB"))
	 appendPointData(tag, &d_eFB);

	 tag = "Fracture_Perienergy_Total";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_eF"))
	 appendPointData(tag, &d_eF);

	 tag = "Total_Energy";
	 double te = d_te - d_tw + d_tk;
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_e"))
	 appendFieldData(tag, te);

	 tag = "Total_Fracture_Perienergy_Bond";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_eFB"))
	 appendFieldData(tag, d_teFB);

	 tag = "Total_Fracture_Perienergy_Total";
	 if (deck->getOutputDeck()->isTagInOutput(tag)
	 && d_policy_p->populateData("Model_d_eF"))
	 appendFieldData(tag, d_teF);

	 */

	close();

}

