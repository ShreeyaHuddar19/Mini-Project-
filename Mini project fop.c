#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ---------------- STRUCTURE ----------------
struct Question {
    char question[300];
    char options[4][150];
    int correct;
};

// ---------------- GLOBAL SCORE ----------------
int totalScore = 0;
int totalQuestions = 0;

// ---------------- FUNCTION DECLARATIONS ----------------
void shuffle(struct Question *q, int n);
void runQuiz(struct Question *q, int index, int size, int *score);
void startQuiz(struct Question *bank, int size, char name[]);
void mixedQuiz();
void menu();

// =======================================================
// SHUFFLE FUNCTION (Uses POINTERS)
// =======================================================
void shuffle(struct Question *q, int n) {
    for(int i=n-1;i>0;i--) {
        int j = rand()%(i+1);

        struct Question temp = *(q+i);
        *(q+i) = *(q+j);
        *(q+j) = temp;
    }
}

// =======================================================
// RECURSIVE QUIZ FUNCTION
// =======================================================
void runQuiz(struct Question *q,int index,int size,int *score){

    if(index==size) return;

    int ans;

    printf("\nQ%d: %s\n",index+1,(q+index)->question);

    for(int i=0;i<4;i++)
        printf("%d. %s\n",i+1,(q+index)->options[i]);

    printf("Enter answer: ");
    scanf("%d",&ans);

    if(ans==(q+index)->correct){
        printf("Correct!\n");
        (*score)++;
    } else {
        printf("Wrong! Correct answer: %d\n",(q+index)->correct);
    }

    runQuiz(q,index+1,size,score);  // recursion
}

// =======================================================
// GENERIC QUIZ STARTER
// =======================================================
void startQuiz(struct Question *bank,int size,char name[]) {

    int score = 0;

    shuffle(bank,size);
    runQuiz(bank,0,size,&score);

    printf("\n%s Score: %d/%d\n",name,score,size);

    totalScore += score;
    totalQuestions += size;
}

// =======================================================
// ---------------- QUESTION BANKS ----------------
// =======================================================

// ---------- QUANTUM (Sample Core Set) ----------
struct Question quantum[] = {
 {"Wave nature becomes significant for:",
         "Large bodies", "Subatomic particles", "Planets", "Cars", 2},

        {"De Broglie proposed that:",
         "Only light has wave nature", "Matter has dual nature",
         "Electrons are only particles", "Waves cannot behave as particles", 2},

        {"De Broglie wavelength is:",
         "h/mv^2", "h/p", "mvh", "mv/h", 2},

        {"If momentum increases, wavelength:",
         "Increases", "Decreases", "Remains constant", "Becomes zero", 2},

        {"Wave nature not observed in macroscopic objects because:",
         "Wavelength extremely small", "They move slowly",
         "No momentum", "Planck constant large", 1},

        {"De Broglie wavelength depends on:",
         "Charge only", "Momentum", "Temperature only", "Volume", 2},

        {"Phase velocity is:",
         "Velocity of particle", "Velocity of wave phase",
         "Velocity of light only", "Zero velocity", 2},

        {"Group velocity represents:",
         "Wave amplitude", "Particle velocity",
         "Frequency", "Energy loss", 2},

        {"Phase velocity can exceed c because:",
         "Carries matter", "Carries no information",
         "Violates relativity", "Imaginary", 2},

        {"Uncertainty principle states we cannot know exactly:",
         "Mass and charge", "Position and momentum",
         "Energy and charge", "Velocity and time", 2},

        {"Mathematical form is:",
         "h", "h/2pi", "h/4pi", "4pi h", 3},

        {"If position uncertainty decreases, momentum uncertainty:",
         "Decreases", "Increases", "Zero", "Constant", 2},

        {"Uncertainty principle significant for:",
         "Cricket balls", "Cars", "Electrons", "Buildings", 3},

        {"Psi represents:",
         "Energy", "Wave function", "Momentum", "Velocity", 2},

        {"|Psi|^2 represents:",
         "Energy density", "Probability density",
         "Charge density", "Mass density", 2},

        {"Valid wave function must be:",
         "Discontinuous", "Infinite", "Single valued & finite", "Negative only", 3},

        {"Wave function must be continuous because:",
         "Probability finite", "Energy zero",
         "Particle stops", "Velocity constant", 1},

        {"Schrodinger equation describes:",
         "Classical motion", "Quantum state evolution",
         "Thermodynamics", "Gravity", 2},

        {"Time-independent equation used when:",
         "Potential varies", "Energy constant",
         "Particle stops", "Velocity zero", 2},

        {"Eigenvalues represent:",
         "Allowed energies", "Forbidden energies",
         "Velocities", "Charges", 1},

        {"Inside infinite potential well, PE is:",
         "Infinite", "Zero", "Negative", "Variable", 2},

        {"At walls of box, wave function is:",
         "Maximum", "Zero", "Infinite", "Constant", 2},

        {"Energy levels are:",
         "Continuous", "Quantized", "Negative only", "Zero", 2},

        {"Ground state energy non-zero because:",
         "Particle cannot be at rest", "Potential zero",
         "Box finite", "Mass constant", 1},

        {"Energy proportional to:",
         "n", "n^2", "1/n", "Constant", 2},

        {"In finite well, wave function outside is:",
         "Zero", "Decays exponentially",
         "Infinite", "Constant", 2},

        {"Quantum tunnelling means:",
         "Stops at barrier", "Crosses barrier without enough energy",
         "Breaks barrier", "Loses energy", 2},

        {"STM works on:",
         "Photoelectric effect", "Tunnelling effect",
         "Diffraction", "Reflection", 2},

        {"De Broglie wavelength depends inversely on:",
         "Mass", "Momentum", "Energy", "Velocity", 2},

        {"Ground state energy of particle in box proportional to:",
         "L", "1/L", "1/L^2", "L^2", 3}
        };
// ---------- PHOTONICS ----------
struct Question photonics[] = {

        {"LASER stands for:",
         {"Light Amplification by Spontaneous Emission of Radiation",
          "Light Amplification by Stimulated Emission of Radiation",
          "Light Absorption by Stimulated Emission of Radiation",
          "Light Amplification by Standard Emission of Radiation"},
         2},

        {"The basic principle behind laser operation is:",
         {"Reflection","Refraction","Stimulated emission","Diffraction"},
         3},

        {"Population inversion is achieved when:",
         {"Lower energy level has more electrons",
          "Higher energy level has more electrons than lower level",
          "Equal electrons in both levels",
          "No electrons in excited state"},
         2},

        {"The process of supplying energy to achieve population inversion is called:",
         {"Amplification","Pumping","Excitation","Ionization"},
         2},

        {"The optical cavity in a laser consists of:",
         {"Two convex lenses","Two parallel mirrors","Two prisms","A single mirror"},
         2},

        {"Laser light is highly:",
         {"Divergent","Incoherent","Monochromatic","Random"},
         3},

        {"The property that describes fixed phase relationship is:",
         {"Directionality","Intensity","Coherence","Reflection"},
         3},

        {"Compared to ordinary light, laser light is:",
         {"Less intense","Highly directional","Multicolored","Incoherent"},
         2},

        {"The active medium in He-Ne laser is:",
         {"Solid crystal","Liquid dye","Gas mixture","Semiconductor"},
         3},

        {"The common wavelength of a He-Ne laser is:",
         {"400 nm","632.8 nm","800 nm","1064 nm"},
         2},

        {"In He-Ne laser, the main lasing atoms are:",
         {"Helium","Neon","Hydrogen","Argon"},
         2},

        {"Holography is based on:",
         {"Refraction","Interference","Polarization","Dispersion"},
         2},

        {"In medicine, lasers are commonly used for:",
         {"Cooling tissues","Blood pressure measurement","Eye surgery (LASIK)","X-ray imaging"},
         3},

        {"In industries, lasers are widely used for:",
         {"Grinding","Cutting and welding","Painting","Polishing manually"},
         2},

        {"In Information Technology, lasers are used in:",
         {"Printers and optical fiber communication","Keyboards","RAM chips","Speakers"},
         1},

        {"Optical fiber works on the principle of:",
         {"Diffraction","Refraction","Total Internal Reflection","Polarization"},
         3},

        {"Acceptance angle is defined as the maximum angle at which light:",
         {"Gets absorbed","Can enter the fiber and propagate",
          "Gets reflected outside","Gets refracted out"},
         2},

        {"Numerical Aperture (NA) indicates the:",
         {"Length of fiber","Speed of light",
          "Light gathering capacity of fiber","Refractive index of air"},
         3},

        {"In step-index fiber, the refractive index:",
         {"Gradually decreases",
          "Is constant in core and suddenly drops in cladding",
          "Is same everywhere",
          "Increases outward"},
         2},

        {"Graded-index fiber reduces:",
         {"Absorption loss","Scattering","Modal dispersion","Reflection"},
         3}
};

// ---------- WAVE OPTICS ----------
struct Question wave[] = {
// ---------------- INTERFERENCE (1–9) ----------------
    {"1. Fringe width in YDSE is:", 
     {"1) lambda D / d","2) d / lambda D","3) lambda d / D","4) D / lambda d"}, 1},

    {"2. Central fringe in YDSE is:", 
     {"1) Dark","2) Bright","3) Colored","4) Invisible"}, 2},

    {"3. Condition for constructive interference is:", 
     {"1) Path difference = n lambda",
      "2) Path difference = (2n+1) lambda/2",
      "3) Path difference = lambda/4",
      "4) Path difference = 0 only"}, 1},

    {"4. Phase shift pi occurs when reflection is from:", 
     {"1) Rarer to denser","2) Denser to rarer","3) Same medium","4) Vacuum"}, 1},

    {"5. Newton's rings are formed due to:", 
     {"1) Diffraction","2) Interference","3) Polarization","4) Refraction"}, 2},

    {"6. Central spot in Newton's rings is:", 
     {"1) Bright","2) Dark","3) Colored","4) Absent"}, 2},

    {"7. Anti-reflection coating works on principle of:", 
     {"1) Refraction","2) Polarization","3) Destructive interference","4) Diffraction"}, 3},

    {"8. Fringe width increases if:", 
     {"1) d increases","2) D decreases","3) lambda increases","4) lambda decreases"}, 3},

    {"9. Path difference for first dark fringe is:", 
     {"1) lambda","2) lambda/2","3) 2 lambda","4) lambda/4"}, 2},

    // ---------------- DIFFRACTION (10–17) ----------------
    {"10. First minimum in single slit diffraction occurs when:", 
     {"1) a sin(theta) = lambda",
      "2) a sin(theta) = 2 lambda",
      "3) a cos(theta) = lambda",
      "4) a = lambda"}, 1},

    {"11. Central maximum in diffraction is:", 
     {"1) Narrow","2) Same as others","3) Broad and intense","4) Absent"}, 3},

    {"12. Resolving power of grating is proportional to:", 
     {"1) 1/N","2) N","3) lambda","4) slit width"}, 2},

    {"13. Grating equation is:", 
     {"1) d sin(theta)=n lambda",
      "2) d cos(theta)=n lambda",
      "3) a sin(theta)=lambda",
      "4) n sin(theta)=d lambda"}, 1},

    {"14. Diffraction is significant when slit width is:", 
     {"1) Very large","2) Comparable to wavelength","3) Zero","4) Infinite"}, 2},

    {"15. Intensity at minima is:", 
     {"1) Maximum","2) Zero","3) Half","4) Infinite"}, 2},

    {"16. Angular width of central maximum is:", 
     {"1) lambda/a","2) a/lambda","3) lambda D","4) d/lambda"}, 1},

    {"17. Fraunhofer diffraction occurs when source is:", 
     {"1) Very near","2) At infinity","3) Inside slit","4) Behind screen"}, 2},

    // ---------------- POLARIZATION (18–25) ----------------
    {"18. Light is transverse because it shows:", 
     {"1) Refraction","2) Interference","3) Polarization","4) Diffraction"}, 3},

    {"19. Brewster angle formula:", 
     {"1) tan(theta_p)=n",
      "2) sin(theta)=n",
      "3) cos(theta)=n",
      "4) theta=90"}, 1},

    {"20. At Brewster angle, reflected and refracted rays are:", 
     {"1) Parallel","2) Perpendicular","3) Same","4) Random"}, 2},

    {"21. Malus Law is:", 
     {"1) I=I0 sin(theta)",
      "2) I=I0 cos(theta)",
      "3) I=I0 cos^2(theta)",
      "4) I=I0 tan(theta)"}, 3},

    {"22. Quarter wave plate introduces phase difference of:", 
     {"1) pi","2) pi/2","3) 2pi","4) pi/4"}, 2},

    {"23. Half wave plate introduces phase difference of:", 
     {"1) pi","2) pi/2","3) pi/4","4) 2pi"}, 1},

    {"24. Polarization by reflection occurs at:", 
     {"1) Critical angle","2) Brewster angle","3) 90 deg","4) 0 deg"}, 2},

    {"25. Polaroids are used in:", 
     {"1) LCD","2) Sunglasses","3) 3D movies","4) All of these"}, 4}
};

// ---------- SEMICONDUCTORS ----------
struct Question semi[] = {
{"If the doping concentration of an n-type semiconductor is increased, what happens to the Fermi level?",
         {"It moves into the valence band",
          "It shifts closer to the conduction band",
          "It shifts closer to the valence band",
          "It remains unchanged"},
         2},

        {"What occurs when a p-n junction diode is forward biased?",
         {"The diode stops conducting entirely",
          "The potential barrier decreases, allowing current to flow",
          "The potential barrier increases, preventing current flow",
          "The diode becomes an insulator"},
         2},

        {"If the resistivity ρ of a semiconductor is given as 0.1 Ωm, what is the conductivity σ using the relationship σ=1/ρ?",
         {"10 S/m",
          "1 S/m",
          "0.1 S/m",
          "0.01 S/m"},
         1},

        {"What is the electric field E in a depletion region of width W of 1 μm when a reverse bias voltage VR=5 V is applied? Use the formula E=VR/W.",
         {"7500000 V/m",
          "5000000 V/m",
          "1000000 V/m",
          "2500000 V/m"},
         2},

        {"True or false?\n Intrinsic semiconductors have a constant number of charge carriers at all temperatures.",
         {"True",
          "False",
          "None",
          "Not Applicable"},
         2},

        {"What is the energy gap (Eg) for silicon at room temperature?",
         {"0.72 eV",
          "1.12 eV",
          "1.5 eV",
          "3.0 eV"},
         2},

        {"If the Fermi energy level (EF) is at 0 K, what is the probability of occupancy for states exactly at EF?",
         {"0.25",
          "0",
          "1",
          "0.5"},
         4},

        {"For a semiconductor where the energy gap (Eg) is less than 2 eV, what happens to its conductivity as the temperature increases?",
         {"Conductivity remains constant",
          "Conductivity becomes zero",
          "Conductivity decreases",
          "Conductivity increases"},
         4},

        {"How many electrons fill the valence band of silicon when N atoms are combined to form a solid?",
         {"2N electrons",
          "4N electrons",
          "3N electrons",
          "N electrons"},
         2},

        {"In the band theory of solids, what is the characteristic of a conductor?",
         {"There is a significant energy gap between the bands",
          "The conduction band overlaps with the valence band",
          "The valence band is completely filled",
          "The conduction band is completely empty"},
         2},

        {"At absolute zero temperature (0 K), how are the energy levels occupied in a conductor?",
         {"Only the conduction band is filled",
          "All energy levels are empty",
          "The Fermi level is partially filled with electrons",
          "All energy levels below the Fermi level are filled"},
         4},

        {"Which of the following statements is true regarding insulators?",
         {"They have low resistivity at high temperatures",
          "They have overlapping conduction and valence bands",
          "They can conduct electricity under certain conditions, but not at room temperature.",
          "They have a wide energy gap (≥3 eV) between the valence and conduction bands"},
         4},

        {"What happens to the Fermi level in a p-type semiconductor as the temperature increases?",
         {"It moves upward toward the valence band.",
          "It oscillates between the valence band and the conduction band.",
          "It moves downward into the conduction band.",
          "It remains fixed at the top of the valence band."},
         1},

        {"In an n-type semiconductor at absolute zero, the Fermi level is typically located:",
         {"Below the bottom of the conduction band.",
          "At the midpoint of the forbidden energy gap.",
          "Between the donor levels and the conduction band edge.",
          "At the top of the valence band."},
         3},

        {"Which of the following statements about drift current is true?",
         {"It is significant in both intrinsic and extrinsic semiconductors under certain conditions.",
          "It occurs without the presence of an external electric field.",
          "It occurs due to the motion of charge carriers under an applied electric field.",
          "It results from a concentration gradient of charge carriers."},
         3},

        {"The Hall coefficient (RH) is defined as:",
         {"The ratio of the Hall voltage to the product of current and magnetic field in the material.",
          "The inverse of the electric field applied across the semiconductor.",
          "The product of charge carrier concentration and mobility.",
          "The ratio of the Hall electric field to the product of current density and magnetic field."},
         4},

        {"What is the primary cause of charge carrier movement in diffusion current?",
         {"A concentration gradient of charge carriers.",
          "Temperature fluctuations in the semiconductor.",
          "The presence of magnetic fields.",
          "An applied external electric field."},
         1},

        {"As impurity concentration increases in an n-type semiconductor, the Fermi level:",
         {"Remains static at the center of the band gap.",
          "Becomes irrelevant to the semiconductor's behavior.",
          "Moves closer to the conduction band.",
          "Moves down toward the valence band."},
         3},

        {"What is the primary cause of reverse saturation current in a p-n junction diode?",
         {"Leakage current through the p-n junction.",
          "External reverse bias voltage affecting the majority carriers.",
          "Majority carriers overcoming the potential barrier.",
          "Minority carriers generated due to thermal generation."},
         4},

        {"In a Zener diode, what is the primary mechanism that allows it to operate in breakdown mode at low reverse voltages?",
         {"Thermal runaway caused by excessive heat generation in the diode's junction region.",
          "Zener breakdown due to a strong electric field in a thin depletion region.",
          "Avalanche breakdown due to high minority carrier injection.",
          "Forward bias causing excessive current flow."},
         2}
};

// =======================================================
// MIXED QUIZ (POINTER COPY FROM ALL ARRAYS)
// =======================================================
void mixedQuiz() {

    int sizeQ = sizeof(quantum)/sizeof(quantum[0]);
    int sizeP = sizeof(photonics)/sizeof(photonics[0]);
    int sizeW = sizeof(wave)/sizeof(wave[0]);
    int sizeS = sizeof(semi)/sizeof(semi[0]);

    int total = sizeQ + sizeP + sizeW + sizeS;

    struct Question mixed[100];

    struct Question *ptr = mixed;

    for(int i=0;i<sizeQ;i++) *(ptr++) = quantum[i];
    for(int i=0;i<sizeP;i++) *(ptr++) = photonics[i];
    for(int i=0;i<sizeW;i++) *(ptr++) = wave[i];
    for(int i=0;i<sizeS;i++) *(ptr++) = semi[i];

    int score = 0;

    shuffle(mixed,total);

    printf("\n=== MIXED PRACTICE QUIZ ===\n");

    runQuiz(mixed,0,total,&score);

    printf("Mixed Score: %d/%d\n",score,total);

    totalScore += score;
    totalQuestions += total;
}

// =======================================================
// MENU (RECURSIVE)
// =======================================================
void menu() {

    int choice;

    printf("\n=========== ENGINEERING PHYSICS QUIZ ===========\n");
    printf("1. Quantum Mechanics\n");
    printf("2. Photonics\n");
    printf("3. Wave Optics\n");
    printf("4. Semiconductors\n");
    printf("5. Mixed Practice\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(choice==1){ startQuiz(quantum,sizeof(quantum)/sizeof(quantum[0]),"Quantum"); menu(); }
    else if(choice==2){ startQuiz(photonics,sizeof(photonics)/sizeof(photonics[0]),"Photonics"); menu(); }
    else if(choice==3){ startQuiz(wave,sizeof(wave)/sizeof(wave[0]),"Wave"); menu(); }
    else if(choice==4){ startQuiz(semi,sizeof(semi)/sizeof(semi[0]),"Semiconductor"); menu(); }
    else if(choice==5){ mixedQuiz(); menu(); }
    else if(choice==6){
        printf("\nFINAL SCORE: %d/%d\n",totalScore,totalQuestions);
        printf("Percentage: %.2f%%\n",(totalScore*100.0)/totalQuestions);
        return;
    }
    else{
        printf("Invalid choice!\n");
        menu();
    }
}

// =======================================================
// MAIN
// =======================================================
int main() {

    srand(time(NULL));  // random seed

    printf("ENGINEERING PHYSICS RANDOMIZED QUIZ SYSTEM\n");

    menu();

    return 0;
}
