Task: Adventure Quest - CLI RPG Game
Objective:
Design and implement a fully interactive Command-Line Interface (CLI) Role-Playing Game (RPG) named "Adventure Quest", leveraging C++ concepts such as abstract classes, interfaces (pure virtual functions), dynamic polymorphism, and Run-Time Type Identification (RTTI). The game should provide an engaging experience where players explore a fantasy world, interact with various characters, engage in turn-based combat, complete quests, and manage their character's progression.

Concept Overview:
The game will use object-oriented programming principles to create a modular and extensible RPG simulation. Key C++ concepts must be applied as follows:
Abstract Class: Use an abstract base class Character to define common attributes and behaviors for all game characters (Heroes, Monsters, NPCs).
Interfaces: Implement pure abstract interfaces (Interactable, Combatable) to define specific interaction and combat behaviors that can be dynamically applied to characters.
Dynamic Polymorphism: Utilize virtual functions and raw pointer-based polymorphism to handle different types of characters, interactions, and combat scenarios dynamically.
RTTI: Employ RTTI (e.g., dynamic_cast, typeid) to identify specific character types at runtime and apply type-specific behaviors (e.g., unique dialogue or combat effects).
Manual Memory Management: Use raw pointers for dynamic memory allocation and ensure proper cleanup with destructors to avoid memory leaks.

Game Description:
"Adventure Quest" immerses the player in a fantasy world filled with heroes, monsters, and non-playable characters (NPCs). The player takes on the role of a hero who explores different locations (e.g., forests, dungeons, villages), interacts with NPCs to uncover the storyline and receive quests, and engages in turn-based battles with monsters. Choices made by the player dynamically affect the game flow, storyline progression, and character development.

Detailed Task Explanation:
Game Entities:
Hero:
The player-controlled character who can interact, fight, level up, manage an inventory, and gain new skills.
Subtypes (optional): Warrior (high health, melee-focused), Mage (magic-focused, ranged attacks), Rogue (stealth and critical hits).
Attributes: Health, attack power, defense, experience points (XP), level, inventory (items like potions, weapons), and skills/spells.
Monster:
Hostile entities that the hero encounters and battles.
Subtypes: Goblin (weak but fast), Troll (high health, slow), Dragon (strong, with special abilities like fire breath).
Attributes: Health, attack power, defense, special abilities (e.g., poison attack, area damage).
NPC:
Non-hostile characters that provide story elements, quests, or items.
Subtypes: Villager (provides quests), Merchant (sells items), Healer (restores health).
Attributes: Name, dialogue, associated quest or items.
Gameplay Mechanics:
Exploration:
The game world consists of multiple textual environments (e.g., "Enchanted Forest", "Dark Dungeon", "Quiet Village").
Players navigate between locations via a CLI menu (e.g., "1. Move to Forest", "2. Move to Village").
Each location contains unique encounters (e.g., meeting an NPC, finding an item, or encountering a monster).
Interactions:
Players can interact with NPCs and certain objects (e.g., treasure chests) using textual prompts.
Use RTTI to vary interactions based on character types (e.g., a Merchant NPC might offer different dialogue to a Warrior than to a Mage).
Example Interaction: Talking to a Villager NPC might yield a quest like "Slay the Troll in the Dark Dungeon."
Combat:
Combat is turn-based, with the player selecting actions (e.g., "Attack", "Use Skill", "Defend", "Use Item") via a CLI menu.
Use dynamic polymorphism to handle combat between heroes and monsters, allowing for diverse behaviors (e.g., a Troll might have a chance to counterattack).
RTTI can be used to apply type-specific effects (e.g., a Mage's spell deals bonus damage to a Dragon).
Example Combat Flow:


A Troll appears! Health: 80 | Attack: 12
Your turn:
1. Attack
2. Use Fireball (Mage skill)
3. Defend
4. Use Potion
Choose an action: 2
You cast Fireball! Deals 25 damage to Troll.
Troll attacks! Deals 8 damage to you.







Inventory and Skills:
The hero has an inventory to store items (e.g., Health Potion, Sword, Magic Amulet).
Items can be used in combat (e.g., a potion restores health) or during exploration (e.g., a key unlocks a door).
Skills/spells are tied to the hero's type (e.g., Warrior: "Power Strike", Mage: "Fireball", Rogue: "Stealth Attack").
Story and Quests:
Implement a simple storyline with branching dialogues and quests.
Quests involve objectives like "Defeat 3 Goblins", "Find the Lost Amulet", or "Rescue a Villager from the Dungeon".
Completing quests rewards the hero with XP, items, or story progression.
Example Quest Flow:

Villager: "A Troll has been terrorizing our village! Please slay it."
Quest Accepted: Slay the Troll in the Dark Dungeon.
[After defeating the Troll]
Villager: "Thank you, hero! Take this Magic Amulet as a reward."
Quest Completed! Gained 50 XP and Magic Amulet.




Progression and Saving:
The hero gains XP from battles and quests, leveling up to improve stats (e.g., health, attack power).
Implement a save/load system to store the game state (hero stats, inventory, quest progress) in a file and load it back.
Technical Requirements:
Abstract Class: Character:
Base class for all entities (Hero, Monster, NPC).
Data members: name, health, attackPower, defense.
Pure virtual functions: displayStats(), takeDamage().
Virtual destructor for proper cleanup of derived classes.
Interfaces:
Interactable: Pure virtual functions like interact(Character* target), getDialogue().
Combatable: Pure virtual functions like attack(Character* target), useAbility(Character* target).
Dynamic Polymorphism:
Use vectors of Character* raw pointers to manage all entities in a location.
Polymorphic behavior in combat (e.g., a Warrior's attack() differs from a Mage's attack()).
RTTI:
Use dynamic_cast to identify specific types (e.g., if (dynamic_cast<Mage*>(hero)) { /* Mage-specific effect */ }).
Example: A Dragon might deal extra fire damage to a Warrior but take extra damage from a Mage’s spells.
Manual Memory Management:
Use raw pointers (Character*, Item*, etc.) for dynamically allocated objects.
Ensure proper cleanup in destructors of classes that manage these pointers (e.g., delete all dynamically allocated objects in GameWorld or Hero destructors).
Avoid memory leaks by carefully managing ownership (e.g., document which class owns a pointer and is responsible for deleting it).

Project Structure:
The project should follow the structure below for clarity and organization:

AdventureQuestCLI/
│
├── include/                    # Directory for header files
│   ├── Character.h           # Abstract base class for all characters
│   ├── Hero.h               # Hero class declaration (player character)
│   ├── Monster.h            # Monster class declaration (hostile entities)
│   ├── NPC.h                # NPC class declaration (non-hostile entities)
│   ├── Interactable.h       # Interface for interaction behavior
│   ├── Combatable.h         # Interface for combat behavior
│   ├── GameWorld.h          # Class to manage locations and entities
│   ├── QuestManager.h       # Class to manage quests and rewards
│   └── Utility.h            # Helper functions (input validation, file handling)
│
├── src/                        # Directory for source files
│   ├── main.cpp              # Entry point for user interaction and game loop
│   ├── Character.cpp         # Character class implementation
│   ├── Hero.cpp             # Hero class implementation
│   ├── Monster.cpp          # Monster class implementation
│   ├── NPC.cpp              # NPC class implementation
│   ├── GameWorld.cpp        # GameWorld class implementation
│   ├── QuestManager.cpp     # QuestManager class implementation
│   └── Utility.cpp          # Implementation of helper functions
│
├── test/                       # Directory for test files
│   ├── TestCharacter.cpp     # Tests for Character class functionality
│   ├── TestHero.cpp         # Tests for Hero class functionality
│   ├── TestMonster.cpp      # Tests for Monster class functionality
│   ├── TestNPC.cpp          # Tests for NPC class functionality
│   ├── TestGameWorld.cpp    # Tests for GameWorld functionality
│   ├── TestQuestManager.cpp # Tests for QuestManager functionality
│   └── TestUtility.cpp      # Tests for Utility functions
│
├── Makefile                    # Makefile for building the project and running tests
└── README.md                   # Project documentation

Detailed Implementation Guidelines:
1. Abstract Class: Character
Header File: include/Character.h
Description: Base class for all entities in the game.
Data members: std::string name, int health, int attackPower, int defense.
Pure virtual functions:
virtual void displayStats() const = 0: Display character stats.
virtual void takeDamage(int damage) = 0: Reduce health based on damage taken.
Virtual destructor: virtual ~Character() = default; to ensure proper cleanup in derived classes.
2. Derived Classes: Hero, Monster, NPC
Header Files: include/Hero.h, include/Monster.h, include/NPC.h
Description:
Hero: Extends Character, implements Interactable and Combatable. Adds inventory (e.g., std::vector<Item*> inventory), skills, XP, and level.
Destructor: Deletes all dynamically allocated items in the inventory.
Monster: Extends Character, implements Combatable. Adds special abilities (e.g., poison attack).
NPC: Extends Character, implements Interactable. Adds dialogue and associated quests/items.
3. Interfaces: Interactable and Combatable
Header Files: include/Interactable.h, include/Combatable.h
Description:
Interactable:
Pure virtual functions: virtual void interact(Character* target) = 0, virtual std::string getDialogue() const = 0.
Used by Hero and NPC to define interaction behavior.
Combatable:
Pure virtual functions: virtual void attack(Character* target) = 0, virtual void useAbility(Character* target) = 0.
Used by Hero and Monster to define combat behavior.
4. Class: GameWorld
Header File: include/GameWorld.h
Description: Manages locations and entities in the game.
Data members: std::vector<Location*> locations, where each Location contains a std::vector<Character*> entities.
Functions: Move the player between locations, trigger encounters (e.g., combat, interaction).
Destructor: Deletes all dynamically allocated Location objects and their Character entities.
5. Class: QuestManager
Header File: include/QuestManager.h
Description: Manages quests and tracks player progress.
Data members: std::vector<Quest*> activeQuests, std::vector<Quest*> completedQuests, rewards (XP, items).
Functions: Assign quests, check completion, distribute rewards.
Destructor: Deletes all dynamically allocated Quest objects.
6. Utility Functions
Header File: include/Utility.h
Description: Helper functions for common tasks.
Input validation (e.g., ensure valid menu choices).
File handling for saving/loading game state (e.g., hero stats, inventory, quest progress).
Random number generation (e.g., for critical hits, enemy spawns).
7. Main Program (Game Loop)
Source File: src/main.cpp
Description: Implements the CLI-based game loop.
Display a welcome message and game instructions.
Allow the player to create a hero (name, type).
Present a main menu with options:
Explore a location.
View hero stats/inventory.
Engage in combat (if a monster is encountered).
Interact with an NPC (if present).
Save/load game progress.
Exit the game.
Ensure proper cleanup of dynamically allocated objects (e.g., delete the GameWorld object before exiting).
8. RTTI Usage
Use RTTI to handle type-specific behavior dynamically.
Example: During combat, check if the hero is a Mage using dynamic_cast and apply a bonus spell effect against a Dragon.
if (Mage* mage = dynamic_cast<Mage*>(hero)) {
    std::cout << "Mage casts a powerful spell, dealing bonus damage!\n";
    target->takeDamage(mage->getAttackPower() + 10);
}


Example: When interacting with an NPC, use typeid to log the type of hero for debugging purposes.
 cpp
CollapseWrapCopy
std::cout << "Interacting with NPC as " << typeid(*hero).name() << "\n";


9. Manual Memory Management Guidelines
Allocation: Dynamically allocate objects (e.g., Character* hero = new Hero("Elara", 80, 15, 5);) when needed.
Deallocation: Ensure every dynamically allocated object is deleted in the appropriate destructor or cleanup function.


Ownership: Clearly document which class owns a pointer and is responsible for deleting it. For example:
GameWorld owns all Location objects.
Each Location owns its Character entities.
Hero owns its inventory items.

Example Gameplay Flow:


Welcome to Adventure Quest!
1. Create Hero
2. Exit
Choose an option: 1

Enter hero name: Elara
Choose hero type (1. Warrior, 2. Mage, 3. Rogue): 2

Hero created: Elara the Mage
Health: 80 | Attack: 15 | Defense: 5

Main Menu:
1. Explore Location
2. View Stats
3. View Inventory
4. Save Game
5. Load Game
6. Exit
Choose an option: 1

Available Locations:
1. Enchanted Forest
2. Dark Dungeon
3. Quiet Village
Choose a location: 1

You enter the Enchanted Forest...
You encounter a Villager!
1. Talk to Villager
2. Ignore
Choose an action: 1

Villager: "A Goblin has stolen my amulet! Please retrieve it."
Quest Accepted: Retrieve the Stolen Amulet.

Main Menu:
...
[Later, in the Dark Dungeon]
A Goblin appears! Health: 50 | Attack: 10
Your turn:
1. Attack
2. Cast Fireball
3. Defend
4. Use Potion
Choose an action: 2

Elara casts Fireball! Deals 30 damage to Goblin.
Goblin attacks! Deals 8 damage to Elara.
Elara defeats the Goblin! Gained 20 XP and Stolen Amulet.




Guidelines for Implementation:
Code Quality:
Write modular, well-documented, and maintainable code.
Use meaningful variable/function names and include comments explaining complex logic.
Memory Safety:
Carefully manage raw pointers to prevent memory leaks or dangling pointers.
Ensure every new has a corresponding delete in the appropriate destructor or cleanup function.
Test for memory leaks using tools like Valgrind (if available) or by logging allocations/deallocations.
Testing:
Write comprehensive unit tests for all classes (e.g., test hero combat, NPC interactions, quest completion).
Include tests to verify proper memory cleanup (e.g., ensure no memory leaks after deleting a GameWorld object).
Use assertions to validate preconditions/postconditions in functions.
Error Handling:
Handle invalid user inputs gracefully (e.g., re-prompt for valid input).
Ensure file operations (save/load) handle errors (e.g., file not found).
Check for null pointers before dereferencing (e.g., if (hero != nullptr) { hero->displayStats(); }).

Submission Requirements:
Project Submission:
Submit the complete project as a github repository.
README.md:
Provide a detailed README.md with the following sections:
Project Overview: Brief description of the game and its features.
Class Structure: Explanation of the class hierarchy, including abstract classes and interfaces.
RTTI Usage: Examples of where and how RTTI is used in the game.
Memory Management: Explanation of how raw pointers are managed, including ownership rules and cleanup strategies.
Gameplay Examples: Sample CLI output showing exploration, interaction, and combat.
Build and Run Instructions: Steps to compile and run the game using the provided Makefile.
Makefile:
Include a Makefile that supports the following commands:
make all: Build the entire project.
make run: Run the game.
make test: Build and run unit tests.
make clean: Clean up generated files.
Feature 1: Portal System
Concept
Instead of moving between locations via a simple menu, players must activate magical portals by solving riddles or using special keys. This introduces a puzzle-solving layer to exploration, making travel more engaging.
Implementation
Portal Class:
Create a Portal class to represent gateways between locations.
Attributes:
sourceLocation: The starting location of the portal.
destinationLocation: The location the portal leads to.
isLocked: A boolean indicating if the portal is currently locked.
activationCondition: Either a riddle (string) with an answer (string) or a required key (item name).
Methods:
attemptActivation(std::string playerInput, Inventory& playerInventory): Checks if the player’s riddle answer is correct or if they have the required key, unlocking the portal if successful.
Riddle System:
Store riddles in a std::map<std::string, std::string> (riddle to answer) within the game.
Example: {"What has keys but can't open locks?", "piano"}.
Prompt the player with the riddle and compare their input to the answer (case-insensitive).
Key System:
Some portals require a specific item (e.g., "Golden Key") in the player’s inventory.
Check the inventory for the item when the player attempts to use the portal.
Integration
Add a std::vector<Portal*> to the GameWorld or Location class to track portals at each location.
In the exploration menu, list available portals with their status (e.g., "Locked Portal to Quiet Village").
When the player selects a portal:
If locked, display the riddle or required key and process their input.
If unlocked (or successfully activated), move the player to the destination location.
Example Interaction

You approach a shimmering portal in the Enchanted Forest.
Portal Guardian: "Answer this riddle to pass: What has keys but can't open locks?"
Your answer: piano
Correct! The portal activates, and you step through to the Quiet Village.





Feature 2: Mounts or Vehicles
Concept
Introduce mounts (e.g., horses) and vehicles (e.g., airships, boats) to enhance travel. Each has unique mechanics: mounts tire out, airships need fuel, and boats are affected by weather conditions like storms.
Implementation
Mount Base Class:
Create a Mount class with:
name: e.g., "Shadowfax" (horse), "Sky Voyager" (airship).
type: Enum (Horse, Airship, Boat).
speedMultiplier: Reduces travel time (e.g., 2x faster).
condition: Tracks fatigue (for mounts) or fuel (for vehicles).
Methods:
useMount(int distance): Updates condition based on travel distance.
restOrRefuel(): Restores condition (e.g., rest for horses, refuel for airships).
Derived Classes:
Horse:
fatigue (0-100): Decreases with use (e.g., -10 per trip). At 0, speed drops to 1x (normal walking speed).
Resting at a stable restores fatigue.
Airship:
fuel (0-100): Decreases with distance (e.g., -5 per unit). At 0, it can’t be used until refueled.
Refuel at specific locations (e.g., a dock).
Boat:
Affected by weather (e.g., "Calm," "Stormy"). Storms increase travel time or trigger events (e.g., detour).
Integration
Add a Mount* currentMount pointer to the Hero class to track the player’s active mount/vehicle.
In the travel menu, if the player owns a mount:
Offer options: "Walk" or "Use [Mount Name]."
Display the mount’s condition and consequences (e.g., "Horse will be fatigued").
Update travel time based on the mount’s speed and condition after use.
Example Interaction

You have a Horse named Shadowfax (Fatigue: 70).
Travel to Dark Dungeon:
1. Walk (takes 2 days)
2. Ride Shadowfax (takes 1 day, Fatigue -20)
Choose an option: 2
You ride Shadowfax to the Dark Dungeon. Shadowfax’s fatigue is now 50.





Feature 3: Time-Sensitive Travel
Concept
Travel between locations takes time, and certain events or quests are only available at specific times of day (e.g., a night market opens in the evening).
Implementation
GameTime Class:
Tracks the current time using an enum: Morning, Afternoon, Evening, Night.
Attributes:
currentTime: The current time of day.
dayCount: Tracks the number of days passed (optional for longer games).
Methods:
advanceTime(int hours): Updates time based on actions (e.g., 6 hours moves Morning to Afternoon).
Travel Time:
Assign each route a time cost (e.g., 12 hours to Quiet Village).
Mounts/vehicles reduce this time based on their speed multiplier.
Time-Sensitive Events:
Tag events/quests with a required time (e.g., "Night Market" only at Evening or Night).
Integration
Display the current time in the game interface (e.g., "Current Time: Morning").
When the player travels, calculate the time taken and advance GameTime.
Restrict access to time-sensitive events based on the current time, notifying the player if they arrive too early/late.
Example Interaction

Current Time: Morning
Travel to Quiet Village (takes 12 hours walking):
[Time advances to Evening]
You arrive at the Quiet Village. It’s now Evening.
The Night Market is now open!




Feature 4: Player Choice Impact
Concept
The player’s choice of travel routes affects game difficulty, triggers unique events, or alters their reputation with NPCs, adding meaningful consequences to decisions.
Implementation
Reputation Class:
Tracks player attributes like bravery, wisdom, etc., as integers (e.g., 0-100).
Methods:
adjustReputation(std::string trait, int amount): Modifies a reputation value.
Route Options:
Define multiple routes per destination with:
riskLevel: Low, Medium, High (affects difficulty).
eventChance: Triggers events like combat or treasure.
reputationImpact: e.g., +10 bravery for a risky route.
Events:
High-risk routes might trigger combat (e.g., bandits) or rewards (e.g., hidden treasure).
Integration
In the travel menu, list routes with descriptions (e.g., "Mountain Pass: High risk, possible bandits").
After travel, apply reputation changes and resolve any events.
NPCs check the player’s reputation to adjust dialogue or quest availability (e.g., "Your bravery impresses me—take this quest!").
Example Interaction

Travel to Dark Dungeon:
1. Safe Road (Low risk, 2 days)
2. Mountain Pass (High risk, 1 day, possible bandits)
Choose a route: 2
You take the Mountain Pass. Bandits ambush you!
[Combat ensues]
You defeat the bandits! Bravery +10.
You arrive at the Dark Dungeon.





Updated Project Structure
To support these features, expand the project as follows:
AdventureQuestCLI/
│
├── include/
│   ├── Character.h
│   ├── Hero.h
│   ├── Monster.h
│   ├── NPC.h
│   ├── Portal.h         # Portal mechanics
│   ├── Mount.h         # Base class for mounts/vehicles
│   ├── Horse.h         # Horse-specific mechanics
│   ├── Airship.h       # Airship-specific mechanics
│   ├── Boat.h          # Boat-specific mechanics
│   ├── GameTime.h      # Time tracking
│   ├── Reputation.h    # Reputation tracking
│   ├── GameWorld.h
│   ├── QuestManager.h
│   └── Utility.h
│
├── src/
│   ├── main.cpp
│   ├── Character.cpp
│   ├── Hero.cpp
│   ├── Monster.cpp
│   ├── NPC.cpp
│   ├── Portal.cpp
│   ├── Mount.cpp
│   ├── Horse.cpp
│   ├── Airship.cpp
│   ├── Boat.cpp
│   ├── GameTime.cpp
│   ├── Reputation.cpp
│   ├── GameWorld.cpp
│   ├── QuestManager.cpp
│   └── Utility.cpp
│
├── test/
│   ├── TestPortal.cpp
│   ├── TestMount.cpp
│   ├── TestGameTime.cpp
│   ├── TestReputation.cpp
│   └── ...
│
├── Makefile
└── README.md




Example Gameplay with All Features


Current Time: Morning
You are in the Quiet Village (Bravery: 0).
Actions:
1. Explore Location
2. Travel
Choose: 2

Travel Options:
1. To Dark Dungeon (Safe Road, 2 days)
2. To Dark Dungeon (Mountain Pass, 1 day, high risk)
Choose: 2

You have a Horse (Fatigue: 80). Ride it? (Y/N): Y
You ride to the Dark Dungeon. [Fatigue -20, Time advances to Afternoon]
Bandits attack on the Mountain Pass! [Combat]
You win! Bravery +10.

You arrive at the Dark Dungeon (Afternoon).
A portal to Hidden Cave is here.
Guardian: "What has a head but never weeps?"
Answer: river
Correct! You enter the Hidden Cave.

Guidelines for Implementation
Portal System: Ensure portals link locations correctly and handle failed activation attempts gracefully.
Mounts/Vehicles: Track conditions (fatigue, fuel) and provide rest/refuel options at specific locations.
Time-Sensitive Travel: Keep time increments consistent and clearly communicate event availability.
Player Choice Impact: Design routes with balanced risk/reward and make reputation affect gameplay meaningfully.

