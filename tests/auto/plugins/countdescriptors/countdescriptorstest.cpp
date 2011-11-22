/******************************************************************************
**
** Copyright (C) 2009-2011 Kyle Lutz <kyle.r.lutz@gmail.com>
** All rights reserved.
**
** This file is a part of the chemkit project. For more information
** see <http://www.chemkit.org>.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
**
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in the
**     documentation and/or other materials provided with the distribution.
**   * Neither the name of the chemkit project nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
******************************************************************************/

#include "countdescriptorstest.h"

#include <algorithm>

#include <chemkit/molecule.h>
#include <chemkit/moleculardescriptor.h>

void CountDescriptorsTest::initTestCase()
{
    std::vector<std::string> descriptors = chemkit::MolecularDescriptor::descriptors();
    QVERIFY(std::find(descriptors.begin(), descriptors.end(), "atom-count") != descriptors.end());
    QVERIFY(std::find(descriptors.begin(), descriptors.end(), "heavy-atom-count") != descriptors.end());
    QVERIFY(std::find(descriptors.begin(), descriptors.end(), "bond-count") != descriptors.end());
    QVERIFY(std::find(descriptors.begin(), descriptors.end(), "ring-count") != descriptors.end());
}

void CountDescriptorsTest::test_data()
{
    QTest::addColumn<QString>("smiles");
    QTest::addColumn<QString>("formula");
    QTest::addColumn<int>("atomCount");
    QTest::addColumn<int>("heavyAtomCount");
    QTest::addColumn<int>("bondCount");
    QTest::addColumn<int>("ringCount");

    QTest::newRow("methane") << "C" << "CH4" << 5 << 1 << 4 << 0;
    QTest::newRow("propane") << "CCC" << "C3H8" << 11 << 3 << 10 << 0;
    QTest::newRow("benzene") << "c1ccccc1" << "C6H6" << 12 << 6 << 12 << 1;
}

void CountDescriptorsTest::test()
{
    QFETCH(QString, smiles);
    QFETCH(QString, formula);
    QFETCH(int, atomCount);
    QFETCH(int, heavyAtomCount);
    QFETCH(int, bondCount);
    QFETCH(int, ringCount);

    chemkit::Molecule molecule(smiles.toStdString(), "smiles");
    QCOMPARE(molecule.formula(), formula.toStdString());
    QCOMPARE(molecule.descriptor("atom-count").toInt(), atomCount);
    QCOMPARE(molecule.descriptor("heavy-atom-count").toInt(), heavyAtomCount);
    QCOMPARE(molecule.descriptor("bond-count").toInt(), bondCount);
    QCOMPARE(molecule.descriptor("ring-count").toInt(), ringCount);
}

QTEST_APPLESS_MAIN(CountDescriptorsTest)
