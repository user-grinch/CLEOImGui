##################################################
# Generates SASCM.ini entries

IN_FILE : str = "CLEOImGui Commands.xml"
OUT_FILE : str = "scrlog.txt"

#
##################################################

import xml.etree.ElementTree as ET

xml_tree = ET.parse(IN_FILE)
xml_root = xml_tree.getroot()

file = open(OUT_FILE, "w")

for header in xml_root: 
    
    # go through <Command ID= "XXX" Name= "YYY">
    opcode_id : str = header.attrib["ID"].replace('x', '')
    opcode_name : str = header.attrib["Name"].lower()
    param_count : int = 0
    line_buffer : str = ""

    # go into <Args> ... </Args>
    for args in header:

        # go into the actual data section
        for data in args:
            param_count = param_count + 1
            line_buffer += "{0} %{1}d% ".format(data.attrib["Desc"].lower(),param_count)

        break # since there would be only 1

    line_buffer = "{0}={1},{2} {3}\n".format(opcode_id, param_count, opcode_name, line_buffer)

    file.write(line_buffer)

file.close()



