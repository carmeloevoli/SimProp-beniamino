#ifndef BENIAMINO_COSMONUS_H
#define BENIAMINO_COSMONUS_H

#include <memory>

#include "KelnerAharonian2008.h"
#include "beniamino.h"
#include "simprop/core/cosmology.h"
#include "simprop/photonFields/CmbPhotonField.h"
#include "simprop/utils/lookupContainers.h"

namespace beniamino {

class CosmoNeutrinos {
 public:
  CosmoNeutrinos(const Beniamino& b);
  virtual ~CosmoNeutrinos() = default;

  double computeNeutrinoFlux(double Enu, double zMax, size_t N = 9) const;

 protected:
  simprop::cosmo::Cosmology m_cosmology;
  simprop::photonfields::CMB m_cmb;
  KelnerAharonian2008::NeutrinoProductionSpectrum m_nuSpec;
  // simprop::utils::LookupTable<200, 101> m_Jp;
  simprop::utils::LookupTable<50, 21> m_Jp;

 protected:
  double I_deps(double EnuObs, double Ep, double z, size_t N = 4) const;
  double I_dEp(double EnuObs, double z, size_t N = 5) const;
};

}  // namespace beniamino

#endif  // SIMPROP_ANALYTICALSOLUTIONS_COSMONUS_H