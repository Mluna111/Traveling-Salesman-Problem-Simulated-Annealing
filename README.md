<h1>TSP using Simulated Annealing</h1>
<p>This project implements a solution to the Traveling Salesman Problem (TSP) using the Simulated Annealing algorithm in C++. The goal is to find the shortest possible tour that visits each city exactly once and returns to the origin city.</p>

<h2>Files in the Project</h2>
<ul>
    <li><strong>SimulatedAnnealing.cpp</strong>: Main file that runs the simulated annealing algorithm.</li>
    <li><strong>City.h</strong>: Header file defining the City class, which represents a city with a name and coordinates.</li>
    <li><strong>Tour.h</strong>: Header file defining the Tour class, which represents a tour of cities and includes methods to manipulate and evaluate the tour.</li>
</ul>

<h2>Libraries Used</h2>
<ul>
    <li><strong>&lt;iostream&gt;</strong>: For input and output operations.</li>
    <li><strong>&lt;fstream&gt;</strong>: For file input operations.</li>
    <li><strong>&lt;vector&gt;</strong>: For using the vector container to store cities.</li>
    <li><strong>&lt;algorithm&gt;</strong>: For using algorithms like random_shuffle to generate random tours.</li>
    <li><strong>&lt;cmath&gt;</strong>: For mathematical functions like sqrt used in distance calculations.</li>
</ul>

<h2>How to Run</h2>
<ol>
    <li>Ensure you have a C++ compiler installed (e.g., g++).</li>
    <li>Place the source files (<code>SimulatedAnnealing.cpp</code>, <code>City.h</code>, <code>Tour.h</code>) in the same directory.</li>
    <li>Open a terminal and navigate to the directory containing the source files.</li>
    <li>Compile the program using the following command:
        <pre><code>g++ -o TSP_SimulatedAnnealing SimulatedAnnealing.cpp</code></pre>
    </li>
    <li>Run the executable:
        <pre><code>./TSP_SimulatedAnnealing</code></pre>
    </li>
</ol>

<h2>Input</h2>
<p>The program requires the following inputs from the user:</p>
<ul>
    <li>Starting Temperature: The initial temperature for the simulated annealing process.</li>
    <li>Cooling Rate: The rate at which the temperature decreases.</li>
    <li>File Name: The name of the file containing the list of cities and their coordinates.</li>
</ul>

<h2>Output</h2>
<p>The program outputs the following:</p>
<ul>
    <li>The initial solution distance and the tour before optimization.</li>
    <li>The number of new states tested and the number of states accepted during the optimization process.</li>
    <li>The final solution distance and the optimized tour.</li>
</ul>

<h2>Sample Run</h2>
<pre>
    *** TSP using Simulated Annealing ***

    Starting Temperature : 100000

    Cooling Rate: .0003

    Please enter a file name (quit to end): Cities.txt

    Cities:
            Gulmira 60 200
            Puente 180 200
            Wheaton 80 180
            Rose Hill 140 180
            Zloda 20 160
            Wrigley 100 160
            Laura Creek 200 160
            Novi Grad 140 140
            Golden City 40 120
            Custer's Grove 100 120
            Westview 180 100
            River's End 60 80
            Helsinki 100 220
            Berlin 150 140
            Tokyo 10 100
            Liver Pool 30 80

    Initial solution distance: 1626
    Tour:
    Berlin -> Liver Pool -> Wrigley -> Rose Hill -> Helsinki -> Custer's Grove -> Puente -> Golden City -> River's End -> Wheaton -> Laura Creek -> Westview -> Gulmira -> Novi Grad -> Tokyo -> Zloda

    Number of new states tested: 38371
    Number of new states accepted: 23779

    Final solution distance: 665
    Tour:
    Wheaton -> Gulmira -> Zloda -> Golden City -> Tokyo -> Liver Pool -> River's End -> Custer's Grove -> Wrigley -> Helsinki -> Rose Hill -> Puente -> Laura Creek -> Westview -> Berlin -> Novi Grad
</pre>
