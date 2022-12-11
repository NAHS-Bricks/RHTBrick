#include <Arduino.h>
#include <nahs-Bricks-OS.h>
// include all features of brick
#include <nahs-Bricks-Feature-Temp.h>
#include <nahs-Bricks-Feature-Humid.h>
#include <nahs-Bricks-Feature-Bat.h>
#include <nahs-Bricks-Feature-Sleep.h>

void setup() {
  // Now register all the features under All
  // Note: the order of registration is the same as the features are handled internally by FeatureAll
  FeatureAll.registerFeature(&FeatureTemp);
  FeatureAll.registerFeature(&FeatureHumid);
  FeatureAll.registerFeature(&FeatureBat);
  FeatureAll.registerFeature(&FeatureSleep);

  // Set Brick-Specific stuff
  BricksOS.setSetupPin(D7);
  FeatureAll.setBrickType(5);

  // Set Brick-Specific (feature related) stuff
  Wire.begin();
  Expander.begin(45);
  FeatureBat.assignExpander(Expander);
  FeatureBat.setPins(1, 2, A0);
  FeatureTemp.setSensorsPin(D5);

  // Finally hand over to BrickOS
  BricksOS.handover();
}

void loop() {
  // Not used on Bricks
}
