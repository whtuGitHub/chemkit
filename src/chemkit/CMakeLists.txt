# setup config.h
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

find_package(Chemkit)
include_directories(${CHEMKIT_INCLUDE_DIRS})

find_package(Boost REQUIRED)

# boost.thread in versions 1.50 and later require boost.chrono
if(${Boost_VERSION} GREATER 104999)
  find_package(Boost COMPONENTS system filesystem thread chrono REQUIRED)
else()
  find_package(Boost COMPONENTS system filesystem thread REQUIRED)
endif()

set(HEADERS
  alphashape.h
  aminoacid.h
  aromaticitymodel.h
  atom.h
  atom-inline.h
  atomtyper.h
  bitset.h
  bond.h
  bond-inline.h
  bondpredictor.h
  cartesiancoordinates.h
  chemkit.h
  concurrent.h
  config.h
  constants.h
  coordinatepredictor.h
  coordinateset.h
  delaunaytriangulation.h
  diagramcoordinates.h
  dynamiclibrary.h
  element.h
  element-inline.h
  fingerprint.h
  fingerprintsimilaritydescriptor.h
  foreach.h
  fragment.h
  fragment-inline.h
  geometry.h
  geometry-inline.h
  graph.h
  graph-inline.h
  internalcoordinates.h
  isotope.h
  lineformat.h
  matrix.h
  moiety.h
  moleculardescriptor.h
  molecularsurface.h
  molecule.h
  molecule-inline.h
  moleculealigner.h
  moleculeeditor.h
  moleculegraphtraits.h
  moleculewatcher.h
  nucleotide.h
  partialchargemodel.h
  plugin.h
  plugin-inline.h
  pluginmanager.h
  pluginmanager-inline.h
  point2.h
  point3.h
  polymer.h
  polymerchain.h
  quaternion.h
  residue.h
  ring.h
  ring-inline.h
  scalarfield.h
  stereochemistry.h
  structuresimilaritydescriptor.h
  substructurequery.h
  unitcell.h
  variant.h
  variantmap.h
  variant-inline.h
  vector2.h
  vector3.h
)

set(SOURCES
  alphashape.cpp
  aminoacid.cpp
  aromaticitymodel.cpp
  atom.cpp
  atomtyper.cpp
  bond.cpp
  bondpredictor.cpp
  cartesiancoordinates.cpp
  chemkit.cpp
  coordinatepredictor.cpp
  coordinateset.cpp
  delaunaytriangulation.cpp
  diagramcoordinates.cpp
  dynamiclibrary.cpp
  element.cpp
  fingerprint.cpp
  fingerprintsimilaritydescriptor.cpp
  fragment.cpp
  geometry.cpp
  internalcoordinates.cpp
  isotope.cpp
  lineformat.cpp
  moiety.cpp
  moleculardescriptor.cpp
  molecularsurface.cpp
  molecule.cpp
  moleculealigner.cpp
  moleculeeditor.cpp
  moleculewatcher.cpp
  nucleotide.cpp
  partialchargemodel.cpp
  plugin.cpp
  pluginmanager.cpp
  polymer.cpp
  polymerchain.cpp
  residue.cpp
  ring.cpp
  scalarfield.cpp
  stereochemistry.cpp
  structuresimilaritydescriptor.cpp
  substructurequery.cpp
  unitcell.cpp
)

add_definitions(
  -DCHEMKIT_LIBRARY
)

add_chemkit_library(chemkit ${SOURCES})
target_link_libraries(chemkit ${Boost_LIBRARIES})

# link to libdl on unix for dlopen/dlclose/dlsym
if(UNIX)
  target_link_libraries(chemkit dl)
endif()

# install header files
install(FILES ${HEADERS} DESTINATION include/chemkit/)
