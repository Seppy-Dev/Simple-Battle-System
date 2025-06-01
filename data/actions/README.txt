Creating new actions is as simple as creating a new .json file!
You can copy one of the example files to give yourself a template if you'd rather.

The functionality of an action is determined by it's "type", which must be included for the file to work!
Valid types are: "ATTACK", and "RECOVERY" (more may be added in future updates)


"type": "ATTACK", <- This determines which of the other fields are actually read.
                     putting an invalid type will prevent the file from loading.

"category": "MAGIC" <- Where in the battle menu the action is stored.
                       (Valid inputs: "MAGIC", "ABILITY")

"name": "Really Cool Attack", <- You can enter anything you want here. The text here will show up
                                 when the action gets used in-game.

"minDamage": 10,
"maxDamage": 20, <- The minimum and maximum amount of damage the action can deal.
                    This only applies to "ATTACK" type actions.
                    (Can input 0 and negative values)

"minRecovery": 10
"maxRecovery": 20 <- The minimum and maximum amount of HP/MP the action can restore.
                     This only applies to "RECOVERY" type actions.
                     (Can input 0 and negative values)

"recoveryType": "HP" <- The stat the action restores
                        (Valid inputs: "HP", "MP")

"mpCost": 15, <- The amount of MP the action requires to be used.
                 (Can input 0 and negative values)

"accuracy": 100, <- The chance (out of 100) for the action to land.
                    Only applies to "ATTACK" type actions.
                    (Values greater than 100 act identically to 100, & Values below 0 act identically to 0)

"priority": 0, <- The level of priority the move should have when calculating the turn order.
                  (If both battlers use a move with the same priority level, normal speed calculation will apply)