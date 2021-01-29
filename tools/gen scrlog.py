##################################################
# Generates scrlog.ini entries

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
    opcode_name : str = header.attrib["Name"]

    line_buffer : str = "{0}={1},*\n".format(opcode_id, opcode_name)

    file.write(line_buffer)

file.close()



