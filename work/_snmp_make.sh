#!/bin/sh
#�ýű���idd-eoc-snmp���������

cd exlib
make clean
make
cd ../snmplib
make clean
make
cd ../agent
make clean
make agent
cd ..
./cp_libs.sh
cd eocsnmptrap
make clean
make
cd ../eocdc
make clean
make
cd ..
./issue_bins.sh
make clean
make
./issue_bins.sh



