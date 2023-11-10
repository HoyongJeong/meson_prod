////////////////////////////////////////////////////////////////////////////////
//   DetCon.cc
//
//   Definitions of DetCon class's member functions.
// And it describes geometry of simulation.
//
//                       - 10. Nov. 2023. Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4UIcommand.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "DetCon.hh"

//////////////////////////////////////////////////
//   Constructor and destructor
//////////////////////////////////////////////////
DetCon::DetCon()
{
	ConstructMaterials();
	DefineDimensions();
}

DetCon::~DetCon()
{
	DestructMaterials();
}

//////////////////////////////////////////////////
//   Define dimensions
//////////////////////////////////////////////////
void DetCon::DefineDimensions()
{
	// World dimensions: Laboratory size
	m_LabX     = 1. * m;   // World x dimension
	m_LabY     = 1. * m;   // World y dimension
	m_LabZ     = 1. * m;   // World z dimension

	// Target dimensions
	m_TarD     =  50. * mm; // Target diameter
	m_TarT     = 300. * mm; // Thickness
}

//////////////////////////////////////////////////
//   Construct everything
//////////////////////////////////////////////////
G4VPhysicalVolume* DetCon::Construct()
{
	// World
	m_LabSolid = new G4Box("LabSolid", m_LabX / 2., m_LabY / 2., m_LabZ / 2.);
	m_LabLV = new G4LogicalVolume(m_LabSolid, m_VacMat, "LabLV");
	m_LabPV = new G4PVPlacement(0, G4ThreeVector(), "LabPV", m_LabLV, 0, false, 0);

	// Cylindrical target
	m_TarSolid = new G4Tubs("TarSolid", 0., m_TarD / 2., m_TarT / 2., 0. * degree, 360. * degree);
	m_TarLV = new G4LogicalVolume(m_TarSolid, m_TarMat, "TarLV");
	new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), "TarPV", m_TarLV, m_LabPV, false, 0);

	return m_LabPV;
}

void DetCon::ConstructMaterials()
{
	const G4double labTemp = 300.0 * kelvin;

	// Elements to be used to construct materials
	m_ElC  = new G4Element(  "Carbon",  "C",  6,  12.0107  * g/mole);
	m_ElN  = new G4Element("Nitrogen",  "N",  7,  14.00674 * g/mole);
	m_ElO  = new G4Element(  "Oxygen",  "O",  8,  15.9994  * g/mole);
	m_ElAr = new G4Element(   "Argon", "Ar", 18,  39.948   * g/mole);

	// Vacuum material
	m_VacMat = new G4Material("Vacuum", 0.1205e-5*g/cm3, 3, kStateGas, labTemp);
	m_VacMat -> AddElement(m_ElN, 75.47/99.95);
	m_VacMat -> AddElement(m_ElO, 23.20/99.95);
	m_VacMat -> AddElement(m_ElAr, 1.28/99.95);

	// Target material
	m_TarMat = new G4Material("Graphite", 1.7*g/cm3, 3, kStateSolid, labTemp);
	m_TarMat -> AddElement(m_ElC, 99.0/100.0);
	m_TarMat -> AddElement(m_ElN,  0.7/100.0);
	m_TarMat -> AddElement(m_ElO,  0.3/100.0);
}

void DetCon::DestructMaterials()
{
	delete m_TarMat;
	delete m_VacMat;

	delete m_ElAr;
	delete m_ElO;
	delete m_ElN;
	delete m_ElC;
}
