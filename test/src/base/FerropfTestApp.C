//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "FerropfTestApp.h"
#include "FerropfApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
FerropfTestApp::validParams()
{
  InputParameters params = FerropfApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

FerropfTestApp::FerropfTestApp(InputParameters parameters) : MooseApp(parameters)
{
  FerropfTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

FerropfTestApp::~FerropfTestApp() {}

void
FerropfTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  FerropfApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"FerropfTestApp"});
    Registry::registerActionsTo(af, {"FerropfTestApp"});
  }
}

void
FerropfTestApp::registerApps()
{
  registerApp(FerropfApp);
  registerApp(FerropfTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
FerropfTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  FerropfTestApp::registerAll(f, af, s);
}
extern "C" void
FerropfTestApp__registerApps()
{
  FerropfTestApp::registerApps();
}
