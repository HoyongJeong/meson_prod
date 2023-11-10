#ifndef DETCON_h
#define DETCON_h 1

////////////////////////////////////////////////////////////////////////////////
//   DetCon.hh
//
//   This file is a header for DetCon class. It's for construction of whole
// geometry of simulation, which includes target geometry and detector geometry.
//
//                       - 10. Nov. 2023. Hoyong Jeong (hoyong5419@korea.ac.kr)
////////////////////////////////////////////////////////////////////////////////

#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"

class G4VPhysicalVolume;

class DetCon: public G4VUserDetectorConstruction
{
  public:
	DetCon();
	virtual ~DetCon();
	virtual G4VPhysicalVolume* Construct();

  private:
	void DefineDimensions();
	void ConstructMaterials();
	void DestructMaterials();

  private:
	// Elements
	G4Element* m_ElC;
	G4Element* m_ElN;
	G4Element* m_ElO;
	G4Element* m_ElAr;

	// Materials
	G4Material* m_VacMat;
	G4Material* m_TarMat;

	// Dimensions and detector setup
	G4double m_LabX, m_LabY, m_LabZ;
	G4double m_TarD, m_TarT;

	// Geometry objects: Lab
	G4Box* m_LabSolid;
	G4LogicalVolume* m_LabLV;
	G4VPhysicalVolume* m_LabPV;

	// Geometry objects: Target
	G4Tubs* m_TarSolid;
	G4LogicalVolume* m_TarLV;
};
#endif
