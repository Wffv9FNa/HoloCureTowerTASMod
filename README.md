# Holocure Tower TAS Mod
A Holocure mod that adds TAS to Tower of Suffering.
## Installation Steps
- Download `HoloCureTowerTASMod.dll` and `CallbackManagerMod.dll` from the latest version of the mod https://github.com/PippleCultist/HoloCureTowerTASMod/releases
- Download `AurieManager.exe` from the latest version of Aurie https://github.com/AurieFramework/Aurie/releases
    - Note: This launcher may be marked as a Trojan by your antivirus. Aurie is opensource and has been used in several modding communities without issues.
- Launch `AurieManager.exe`, click `Add Game`, and select `HoloCure.exe`
    - You can find `HoloCure.exe` through Steam by clicking `Browse local files`
- Click `Install Aurie`
- Click `Add Mods` and add `HoloCureTowerTASMod.dll` and `CallbackManagerMod.dll`
- Running the game either using the executable or through Steam should now launch the mods as well
## Common Issues
If you get issues saying `Missing game executable` when trying to run the game, it's likely that Windows Defender or your antivirus is blocking `AurieLoader.exe` from installing. Try putting it in the whitelist or manually downloading it from `https://github.com/AurieFramework/Aurie/releases` and putting it in the mods folder.
## Creating a TAS run
Your TAS run will be a file named `runData.txt` that will be put in your game directory in the `TASRun` folder (default is `C:\Program Files (x86)\Steam\steamapps\common\HoloCure\TASRun`).

Commands will be in the format `frameNum action` where action can be `pressCharge`, `releaseCharge`, `pressLeft`, `releaseLeft`, `pressRight`, `releaseRight`, `jumpLeft`, `jumpRight`, `setCheckpoint`, and `loadCheckpoint`. `jumpLeft` and `jumpRight` will have a number after them which determine how many frames the jump is charged for.

The console log will print out what frame number your character touches the ground to help optimize your run.
