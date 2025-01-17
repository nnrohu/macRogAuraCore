# macRogAuraCore - rogauracore ported from Linux.

(c) 2020 black.dragon74 aka Nick

macOS-compatible IOHIDKit implementation similar to the ROG
Aura Core software.  Supports RGB keyboards with IDs
[0b05:1854](https://linux-hardware.org/index.php?id=usb:0b05-1854)
(GL553, GL753),
[0b05:1869](https://linux-hardware.org/index.php?id=usb:0b05-1869)
(GL503, FX503, GL703), [0b05:1866](https://linux-hardware.org/index.php?id=usb:0b05-1866) (GL504, GL703, GX501, GM501), and [0b05:19b6](https://linux-hardware.org/index.php?id=usb:0b05-19b6) (GA503).

## Usage

```
Usage:
   macRogAuraCore COMMAND ARGUMENTS

COMMAND should be one of:
   initialize_keyboard
   brightness
   cycle_brightness
   on
   off
   single_static
   single_breathing
   single_colorcycle
   red
   green
   blue
   yellow
   gold
   cyan
   magenta
   white
   black
   rainbow
```

## Command Examples

### Color Effects

#### Single Static Color
Set the entire keyboard to a single color:
```bash
# Red keyboard
macRogAuraCore single_static ff0000

# Green keyboard
macRogAuraCore single_static 00ff00

# Blue keyboard
macRogAuraCore single_static 0000ff
```

#### Single Breathing Effect
Create a breathing effect between two colors:
```bash
# Breathe between red and green
macRogAuraCore single_breathing ff0000 00ff00

# Breathe between blue and white
macRogAuraCore single_breathing 0000ff ffffff
```

#### Quick Color Commands
Instantly set predefined colors:
```bash
macRogAuraCore red
macRogAuraCore green
macRogAuraCore blue
macRogAuraCore white
macRogAuraCore yellow
macRogAuraCore cyan
macRogAuraCore magenta
```

### Lighting Effects

#### Color Cycling
Automatically cycle through colors:
```bash
# Start color cycling
macRogAuraCore single_colorcycle

# Rainbow effect
macRogAuraCore rainbow
```

### Brightness Control

#### Set Brightness
Adjust keyboard brightness (0-3 levels):
```bash
# Lowest brightness
macRogAuraCore brightness 0

# Low-medium brightness
macRogAuraCore brightness 1

# Medium-high brightness
macRogAuraCore brightness 2

# Highest brightness
macRogAuraCore brightness 3

# Cycle through brightness levels
macRogAuraCore cycle_brightness
```

### Power Controls

#### Keyboard Lighting
```bash
# Turn keyboard lights on
macRogAuraCore on

# Turn keyboard lights off
macRogAuraCore off

# Reset keyboard to saved state
macRogAuraCore initialize_keyboard
```

## Color Format
Colors are specified in hexadecimal RGB format:
- `ff0000`: Red
- `00ff00`: Green
- `0000ff`: Blue
- `ffffff`: White

## Karabiner-Elements Integration

### Setting Up Keyboard Lighting Shortcuts

#### Prerequisites
- [Karabiner-Elements](https://karabiner-elements.pqrs.org/) installed
- macRogAuraCore installed in `/usr/local/bin`

#### Step-by-Step Configuration

1. **Open Karabiner Configuration**
   ```bash
   open ~/.config/karabiner/karabiner.json
   ```

2. **Add Keyboard Lighting Shortcuts**
   Modify your `karabiner.json` to include custom key bindings. Here's an example configuration:

   ```json
   {
       "profiles": [
           {
               "complex_modifications": {
                   "rules": [
                       {
                           "description": "ROG Keyboard Lighting Controls",
                           "manipulators": [
                               {
                                   "description": "F6 → Cycle Keyboard Brightness",
                                   "from": {
                                       "key_code": "f6",
                                       "modifiers": { "optional": ["any"] }
                                   },
                                   "to": [{ 
                                       "shell_command": "/usr/local/bin/macRogAuraCore cycle_brightness" 
                                   }],
                                   "type": "basic"
                               },
                               {
                                   "description": "F2 → Set Green Color",
                                   "from": {
                                       "key_code": "f2",
                                       "modifiers": { "optional": ["any"] }
                                   },
                                   "to": [{ 
                                       "shell_command": "/usr/local/bin/macRogAuraCore green" 
                                   }],
                                   "type": "basic"
                               }
                           ]
                       }
                   ]
               }
           }
       ]
   }
   ```

3. **Import Complex Modifications**
   - Open Karabiner-Elements
   - Go to "Complex Modifications" tab
   - Click "Add rule"
   - Select the imported rules

#### Customizing Your Shortcuts

You can add more shortcuts by following the pattern in the example:
- Change `key_code` to the desired function key
- Modify `shell_command` to use any macRogAuraCore command

#### Recommended Shortcuts
- `F6`: Cycle Brightness
- `F2`: Set Green Color
- `F3`: Set Yellow Color
- `F4`: Rainbow Mode

#### Troubleshooting
- Ensure macRogAuraCore is installed in `/usr/local/bin`
- Verify Karabiner-Elements is running
- Check terminal for any error messages

### Tips for Advanced Users
- Use modifiers like `command`, `shift`, or `option` for more complex key bindings
- Experiment with different color and effect combinations
- Restart Karabiner-Elements after modifying the configuration

## Building

### From github:

Install Xcode, clone the github repo and enter the top-level directory.  Then:

```sh
xcodebuild -configuration Release
```

## Credits

- Will Roberts for original `rogauracore` for Linux
