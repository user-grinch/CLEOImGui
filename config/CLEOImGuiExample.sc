SCRIPT_START
{
    /*
        CLEOImGui - ImGui port for CLEO v4.4
        Author: Grinch_

        This script demonstrates usage of most of the widgets

        This script requires, 
            https://forum.mixmods.com.br/f16-utilidades/t179-gta3script-while-true-return_true-e-return_false
            CLEOImGui.cleo
    */

    /*
        It's best to check ImGui documentation first before using any of the widgets. They'll contain more
        information & examples about a certain widget. More than what I can provide here. But I'll provide some
        to make your life easier.

        1. Naming widgets: Every widget must have a unique name. A easy fix for it to add some garbage text 
            with "##" before it (ImGui ignores everything after ##). 
            An example would be "Input##1" and "Input##2"

        2. Must run every frame: The CLEOImGui code needs to run every frame. Meaning you can't 
            use anything other than `WAIT 0`. Use timers instead. 
            https://gtagmodding.com/opcode-database/opcode/01BD/

        3. Do not reuse variables! There's a limitation of CLEOImGui, which is 1 frame delay.
            Don't know if I can explain this properly but here,
            There's a single frame delay from when you use a getter function and when it provides proper value
            Example,
                LVAR_FLOAT fx
                IMGUI_GET_WINDOW_WIDTH fx

                You might expect it to have the value of width but on first frame it'll contain 0. Afterwards
                it'll return the values of the previous frames. You should keep this is mind, very important!
                
    */

    SCRIPT_NAME CLIMGUI

    LVAR_INT shit shown fps pbuffer input_int[3] ptext_buf pint temp pgamedir checkbox pcheckbox texture[3] radio_btn
    LVAR_FLOAT btn_size[2] color_edit[3] input_float[3] health_addr imgui_version cleoimgui_version 
    
    GET_LABEL_POINTER buffer_mem pbuffer
    GET_LABEL_POINTER text_buf ptext_buf
    GET_LABEL_POINTER game_dir_mem pgamedir
    GET_LABEL_POINTER checkbox_mem pcheckbox
    GET_LABEL_POINTER int_mem pint

    WRITE_MEMORY pint 4 100 0 // write value 100

    shown = 1
    color_edit[0] = 1.0

    GET_VAR_POINTER health_addr temp
    WRITE_MEMORY temp 4 0xB793E0 0

    IMGUI_GET_VERSION imgui_version
    IMGUI_GET_CLEO_IMGUI_VERSION cleoimgui_version

    // Load texture only once! (relative from game dir)
    IMGUI_LOAD_TEXTURE "CLEO\resources\carbonfiber.png" texture[0]
    IMGUI_LOAD_TEXTURE "CLEO\resources\stickerbomb.png" texture[1]
    IMGUI_LOAD_TEXTURE "CLEO\resources\uvtest.png" texture[2]
    
    WHILE TRUE
        WAIT 0

        /*
            To create a window we must call the `IMGUI_BEGIN` function.
            Don't forget to end with `IMGUI_END`
        */

        IF IS_KEY_PRESSED VK_TAB
            WHILE IS_KEY_PRESSED VK_TAB
                WAIT 0
            ENDWHILE

            IF shown = TRUE
                shown = FALSE
            ELSE
                shown = TRUE
            ENDIF
        ENDIF

        IF shown = TRUE

            IMGUI_SET_NEXT_WINDOW_SIZE 350.0 650.0 ImGuiCond_Once

            // You need to apply your themes each frame
            // By default the default theme is applied
            // Uncomment below line to change theme
            //IMGUI_STYLE_COLORS_CLASSIC

            // Most of them won't work
            IF checkbox = 1
                IMGUI_SHOW_DEMO_WINDOW
            ENDIF

            READ_MEMORY pcheckbox 4 0 temp
            IF temp = 1
                IMGUI_SHOW_STYLE_EDITOR
            ENDIF

            IF radio_btn = 1
                IMGUI_SET_COLOR ImGuiCol_WindowBg 1.0 1.0 1.0 0.75
            ENDIF
            
            // FYI IMGUI_BEGIN returns false when collasped
            IF IMGUI_BEGIN "CLEO ImGui Example Window" shown ImGuiWindowFlags_None TRUE

                IMGUI_SPACING
            
                IMGUI_GET_FRAMERATE fps
                IMGUI_GET_GAME_PATH pgamedir
                STRING_FORMAT pbuffer "ImGui Version: %0.2f   CLEO ImGui Version %0.2f" (imgui_version cleoimgui_version)
                IMGUI_TEXT $pbuffer

                STRING_FORMAT pbuffer "Frames: %d   Game dir: %s" (fps pgamedir)
                IMGUI_TEXT $pbuffer
                
                IMGUI_SPACING

                IMGUI_COLUMNS 2 0
                IMGUI_CHECKBOX "Show demo window" Var checkbox
                IMGUI_RADIO_BUTTON "Normal bg" Var radio_btn 0
                IMGUI_NEXT_COLUMN
                IMGUI_CHECKBOX "Show style editor" Pointer pcheckbox
                IMGUI_RADIO_BUTTON "White bg" Var radio_btn 1
                IMGUI_COLUMNS 1 0

                IMGUI_DUMMY 0.0 30.0 // add some padding

                CLEO_CALL GetSize 0 (0 2.0) (btn_size[0] btn_size[1])

                IMGUI_BEGIN_CHILD "TEST" 0.0 0.0 FALSE ImGuiWindowFlags_None

                    // ------------------------------------------------------------------
                    // Texts
                    // ------------------------------------------------------------------
                    IF IMGUI_COLLASPING_HEADER "Text widgets" ImGuiTreeNodeFlags_None
                        IMGUI_SPACING
                         
                        IMGUI_TEXT "This is a simple text"
                        IMGUI_TEXT_DISABLED "This is a disabled text"
                        IMGUI_TEXT_COLORED "This is a colored text" 1.0 0.0 0.0 1.0
                        IMGUI_BULLET_TEXT "This is a bullet text" 

                        IMGUI_TEXT_WRAPPED "This is a wrapped text example.This is a wrapped text example.This is a wrapped text example.This is a wrapped text example."

                        IMGUI_SEPARATOR
                        IMGUI_SPACING
                    ENDIF
                    // ------------------------------------------------------------------


                    // ------------------------------------------------------------------
                    // Buttons
                    // ------------------------------------------------------------------
                    IF IMGUI_COLLASPING_HEADER "Button widgets" ImGuiTreeNodeFlags_None
                        IMGUI_SPACING
                            
                        
                        // ImGui windows need to be scaled manually!
                        // Font scaling is done by CLEOImGui

                        IF IMGUI_BUTTON "Button 1" btn_size[0] btn_size[1]
                            PRINT_STRING "Button 1 was pressed" 1000
                        ENDIF

                        IMGUI_SAMELINE

                        IF IMGUI_COLOR_BUTTON "Button 2" 1.0 0.0 0.0 1.0 ImGuiColorEditFlags_None btn_size[0] btn_size[1]
                            PRINT_STRING "Button 2 was pressed" 1000
                        ENDIF

                        IMGUI_SPACING
                        IMGUI_TEXT "Tip: Click below!"
                        
                        IF IMGUI_INVISIBLE_BUTTON "Button 3" btn_size[0] btn_size[1] ImGuiButtonFlags_None
                            PRINT_STRING "Insivisible button was pressed" 1000
                        ENDIF

                        IMGUI_SEPARATOR
                        IMGUI_SPACING
                    ENDIF
                    // ------------------------------------------------------------------


                    // ------------------------------------------------------------------
                    // Color Picker
                    // ------------------------------------------------------------------
                    IF IMGUI_COLLASPING_HEADER "Color widgets" ImGuiTreeNodeFlags_None
                        IMGUI_SPACING

                        // You'll need color_edit[4] if you want WithAlpha
                        IMGUI_TEXT_COLORED "Color edit example" color_edit[0] color_edit[1] color_edit[2] 1.0
                        IMGUI_COLOR_EDIT "Choose color" Var color_edit[0] ImGuiColorEditFlags_None ImGuiColorEdit_WithoutAlpha
                        
                        IMGUI_SPACING
                        
                        IMGUI_TEXT_COLORED "Color picker example" color_edit[0] color_edit[1] color_edit[2] 1.0
                        IMGUI_COLOR_PICKER "Pick color" Var color_edit[0] ImGuiColorEditFlags_None ImGuiColorEdit_WithoutAlpha

                        IMGUI_SEPARATOR
                        IMGUI_SPACING
                    ENDIF
                    // ------------------------------------------------------------------


                    // ------------------------------------------------------------------
                    // Inputs
                    // ------------------------------------------------------------------
                    IF IMGUI_COLLASPING_HEADER "Input widgets" ImGuiTreeNodeFlags_None
                        IMGUI_SPACING

                        // Need to be sequential bytes!
                        IMGUI_TEXT "Int variants"
                        IMGUI_INPUT_INT "Int 1" Pointer pint ImGuiInputTextFlags_None ImGuiInputCount_One
                        IMGUI_INPUT_INT "Int 2" Var input_int[0] ImGuiInputTextFlags_None ImGuiInputCount_Two
                        IMGUI_INPUT_INT "Int 3" Var input_int[0] ImGuiInputTextFlags_None ImGuiInputCount_Three
                        
                        IMGUI_SPACING

                        IMGUI_SLIDER_INT "Slider Int 1" Pointer pint 0 10 ImGuiSliderFlags_None ImGuiSliderCount_One
                        IMGUI_SLIDER_INT "Slider Int 2" Var input_int[0] 0 10 ImGuiSliderFlags_None ImGuiSliderCount_Two
                        IMGUI_SLIDER_INT "Slider Int 3" Var input_int[0] 0 10 ImGuiSliderFlags_None ImGuiSliderCount_Three

                        IMGUI_SPACING

                        IMGUI_TEXT "Float variants"
                        IMGUI_INPUT_FLOAT "Health" Pointer health_addr ImGuiInputTextFlags_None ImGuiInputCount_One
                        IMGUI_INPUT_FLOAT "Float 2" Var input_float[0] ImGuiInputTextFlags_None ImGuiInputCount_Two
                        IMGUI_INPUT_FLOAT "Float 3" Var input_float[0] ImGuiInputTextFlags_None ImGuiInputCount_Three

                        IMGUI_SPACING

                        IMGUI_SLIDER_FLOAT "Slider Float 1" Var input_float[0] 0.0 10.0 ImGuiSliderFlags_None ImGuiSliderCount_One
                        IMGUI_SLIDER_FLOAT "Slider Float 2" Var input_float[0] 0.0 10.0 ImGuiSliderFlags_None ImGuiSliderCount_Two
                        IMGUI_SLIDER_FLOAT "Slider Float 3" Var input_float[0] 0.0 10.0 ImGuiSliderFlags_None ImGuiSliderCount_Three

                        IMGUI_SPACING

                        IMGUI_TEXT "Text variants"
                        IMGUI_INPUT_TEXT "Single input" "Hint example" ptext_buf 31 ImGuiInputTextFlags_None

                        // max 128
                        IMGUI_INPUT_TEXT_MULTILINE "Multiline Input" ptext_buf 128 0.0 0.0 ImGuiInputTextFlags_None
                        
                        IMGUI_SEPARATOR
                        IMGUI_SPACING
                    ENDIF
                    // ------------------------------------------------------------------

                    // ------------------------------------------------------------------
                    // Textures
                    // ------------------------------------------------------------------
                    IF IMGUI_COLLASPING_HEADER "Texture widgets" ImGuiTreeNodeFlags_None
                        IMGUI_SPACING

                        IMGUI_TEXT "A simple image"
                        btn_size[1] = btn_size[1]*3.0
                        IMGUI_IMAGE "Unique text" texture[0] btn_size[0] btn_size[1]
                        IMGUI_SAMELINE
                        IMGUI_IMAGE "Unique text2" texture[1] btn_size[0] btn_size[1]

                        IMGUI_SPACING
                        
                        IMGUI_TEXT "A image button"
                        btn_size[0] = btn_size[0]*2.0

                        IF IMGUI_IMAGE_BUTTON "Unique text3" texture[2] btn_size[0] btn_size[1] 
                            PRINT_STRING "Image button was pressed" 1000
                        ENDIF

                        IMGUI_SEPARATOR
                        IMGUI_SPACING
                    ENDIF
                    // ------------------------------------------------------------------
                IMGUI_END_CHILD

            ENDIF
            IMGUI_END // Don't put this inside! 
        ENDIF

    ENDWHILE
}

    
{
    /*  
        A basic scaling implementation
        Taken from CheatMenu https://github.com/user-grinch/Cheat-Menu/blob/630944460fdadf9dc9a1f2f6be346a7176af62ae/src/Ui.cpp#L52
    */ 
    LVAR_INT spacing
    LVAR_FLOAT count 
    
    LVAR_FLOAT factor x y item_spacingX content_width frame_height

    GetSize:

    IF NOT count = 1.0
		spacing = TRUE
    ENDIF

    IMGUI_GET_STYLE ItemSpacingX item_spacingX
    IMGUI_GET_WINDOW_CONTENT_REGION_WIDTH Var content_width
    IMGUI_GET_FRAME_HEIGHT Var frame_height
    
	factor = item_spacingX / 2.0

	IF count = 3.0
		factor = item_spacingX / 1.403
    ENDIF

	IF spacing = TRUE
		x = content_width / count 
        x = x - factor
	ELSE
		x = content_width / count
    ENDIF

    y = frame_height*1.3
	
    
    CLEO_RETURN 0 (x y)

}
SCRIPT_END

checkbox_mem:
DUMP // 4 bytes
00 00 00 00 
ENDDUMP

int_mem: // 4 bytes
DUMP
00 00 00 00 
ENDDUMP

game_dir_mem: // 64 bytes
DUMP
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 
ENDDUMP

buffer_mem: // 128 bytes
DUMP
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
ENDDUMP

text_buf: // 128 bytes
DUMP
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
ENDDUMP