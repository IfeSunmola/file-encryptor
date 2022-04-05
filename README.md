<h4>DISCLAIMER: THIS PROGRAM SHOULD NOT BE USED WITH FILES CONTAINING SENSITIVE 
INFORMATION. NO SOPHISTICATED FORM OF ENCRYPTION WAS USED HERE. </h4>

**_Side note_**: Below all the print statements, I had to flush the buffer with `fflush(stdout)` so the 
program would work correctly with unix environments, specifically git bash. 

If anyone knows how to avoid using those, feel free to make a pull request, thank you.

<h3>Run `main.c` with: </h3>
<h6>Unix based systems: `clear && g++ main.c && ./a.exe`</h6>
<h6>Windows: `cls && g++ main.c && a.exe`</h6>
<h6>Replace `g++` with the c/c++ compiler you have.</h6>

<img src="images/sample_run.png">


<h2>Sample encryption:</h2>
<h4>File to encrypt -> `test_file.txt`:</h4>
<img src="images/test_file_img.png"/>
<h4>Encrypted file - `encrypted.txt`:</h4>
<img src="images/encrypted.png"/>

<h2>Sample decryption:</h2>
<h4>After decrypting `encrypted.txt`, the output will be stored in `decrypted.txt`:</h4>
<img src="images/decrypted.png"/>

<h4>`test_file.txt` was generated with https://www.plot-generator.org.uk/ </h4>

