# Runs the generation program, which creates the java enumeration classes from the EBV xml file

# This uses exec-maven-plugin to run, but you could run from disenums.jar too.

mvn clean compile

mvn exec:java -Dexec.mainClass=edu.nps.moves.siso.EBVReader

