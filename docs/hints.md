# Author notes (ground truth)

This wiki is generated from `src/`. The following context is not expressible
from the code alone; treat it as authoritative. Layout and tone follow the
Shadows playerbot command manual.

## What this module is

`mod-shadows` is an AzerothCore module that adds player-like bots ("shadows") to
a server. It descends from IKE3's Shadows / mangosbot and the playerbots lineage.
There are two populations:

- **Random bots** — autonomously wander the world, level, do quests, join
  battlegrounds and raids, and emulate the feel of a populated realm.
- **Alt bots** — a player's own alternate characters, logged in on demand to
  party with, level, and be commanded directly.

Bots are driven by a **strategy / trigger / action / value** engine:

| Concept | Meaning |
| --- | --- |
| Strategy | A named group of triggers attached to a bot for a class, role, or situation; the unit that decides "what kind of thing do I do now". |
| Trigger | A condition plus the set of actions to run while it holds (e.g. "low health", "target in melee"). |
| Action | A single executable behaviour (cast a spell, loot, follow, use an item). |
| Value | A lazily-computed number or object that triggers and actions read (health, threat, target, distance). |

Strategies are registered per class and composed at runtime based on the bot's
spec, group role, and current situation. This is why most of `src/strategy/` is
organised by class and by action/trigger/value category.

## Controlling bots

Bots are controlled by chat commands, normally typed by the bot's owner. In-game
UI addons (Multibot and others) wrap these commands. GM/console equivalents
exist where noted.

| Command | Purpose | Security |
| --- | --- | --- |
| `.shadows bot ...` | the main alt-bot command surface (party orders, strategies, chat, gear, etc.) | Player |
| `.shadows rndbot ...` | manage the random-bot population (spawn, reset, teleport, stats) | GM |
| `.shadows gtask ...` | guild-task subsystem (bots earning guild rewards) | GM |
| `.shadows pmon ...` | performance monitor for the AI | GM |
| `.shadows setKey` | set the per-account security key used to link accounts | Player |
| `.shadows link` / `.unlink` / `.linkedAccounts` | link an account so its characters are available as alt bots | Player |
| `.shadows bg ...` | debug battleground bot tactics | GM |

`AiShadow.*` configuration covers bot login and limits, alt-bot maintenance
(gear, spells, talents, consumables, repairs), questing and reward automation,
autogear, random-bot population control, chat/broadcast chatter, guild tasks,
and performance tuning.

## Operator notes

- The `enUS` (English) DBC files must be present or bots will not cast spells.
- Supported platforms are Ubuntu, Windows and macOS; the module builds against
  the `master-shadows` branch of YggdrasilCore.
- `AiShadow.*` settings can be supplied as environment variables in Docker
  (e.g. `AiShadow.RandomBotAutologin` becomes `AC_AI_SHADOW_RANDOM_BOT_AUTOLOGIN`).
