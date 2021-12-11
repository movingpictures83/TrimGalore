#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "TrimGalorePlugin.h"

void TrimGalorePlugin::input(std::string file) {
  inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }
}

void TrimGalorePlugin::run() {
   
}

void TrimGalorePlugin::output(std::string file) {
	//trim_galore --no_report_file --paired -o $out $reads_1 $reads_2
	std::string command = "trim_galore --no_report_file --paired -o "+file+" "+std::string(PluginManager::prefix())+"/"+parameters["forward"]+" "+std::string(PluginManager::prefix())+"/"+parameters["reverse"]+"; cp "+file+"/*.fq "+file+"/../";
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<TrimGalorePlugin> TrimGalorePluginProxy = PluginProxy<TrimGalorePlugin>("TrimGalore", PluginManager::getInstance());
