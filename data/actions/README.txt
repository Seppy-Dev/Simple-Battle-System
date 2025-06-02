Creating new actions is as simple as creating a new .json file!
You can copy one of the example files to give yourself a template if you'd rather.

You do not need to include every property listed here in an action. Most properties have a default value if not entered.
The functionality of an action is determined by it's "type", which must be included for the file to work!
Valid types are: "ATTACK", and "RECOVERY" (more may be added in future updates)


## Required properties (These have no default values and MUST be included in the file, else the action won't register)

"type": "ATTACK", <- This determines which of the other fields are actually loaded by the game.
                     (Valid inputs: "ATTACK", "RECOVERY")

"category": "MAGIC" <- Where in the battle menu the action is stored.
                       (Valid inputs: "MAGIC", "ABILITY")

"name": "Example Magic Attack", <- You can enter anything you want here. The text here will show up
                                   when the action gets used in-game.


## General properties (Applicable on all action types):

"mpCost": 10, <- The amount of MP the action takes to be used.
                 (Can input 0 and negative values)
                 [Default Value: 0]

"hpCost": 0, <- The amount of HP the action takes to be used.
                 (Can input 0 and negative values)
                 [Default Value: 0]

"priority": 0, <- The level of priority the move should have when calculating the turn order.
                  (If both battlers use a move with the same priority level, normal speed calculation will apply)
                  (Can input 0 and negative values)
                  [Default Value: 0]


## Attack properties (Only applicable to "ATTACK" type actions):

"targetStat": "HP" <- The stat of the target which will be targeted by the action (lower enemy's hp or mp)
                      (Valid Inputs: "HP", "MP")
                      [Default Value: "HP"]

"minDamage": 10,
"maxDamage": 20, <- The minimum and maximum amount of damage the action can deal.
                    (Can input 0 and negative values)
                    [minDamage Default Value: 1] (maxDamage defaults to the value of minDamage)

"accuracy": 80, <- The chance (out of 100) for the action to land.
                   (Values greater than 100 act identically to 100, & Values below 0 act identically to 0)
                   [Default Value: 100]

"critRate": 10, <- The chance (out of 100) for the action to result in a critical hit (multiplies damage by 1.5x)
                   (Values greater than 100 act identically to 100, & Values below 0 act identically to 0)
                   [Default Value: 10]

"multiHitMin": 1,
"multiHitMax": 5 <- The minimum and maximum number of times the action can fire in a single turn
                    (If these properties are not set, action will only fire once)
                    [Default Value: 1]

"lifeDrainPercent": 50, <- The percentage of damage dealt by the action that will become HP recovery for the user
                           [Default Value: 0]

"manaDrainPercent": 50, <- The percentage of damage dealt by the action that will become MP recovery for the user
                           [Default Value: 0]


## Recovery Properties (Only applicable to "RECOVERY" type actions):

"minRecovery": 10
"maxRecovery": 20 <- The minimum and maximum amount of HP/MP the action can restore.
                     (Can input 0 and negative values)
                     [Default Value: 1]

"recoveryType": "HP" <- The stat the action restores
                        (Valid inputs: "HP", "MP")
                        [Default Value: "HP"]
