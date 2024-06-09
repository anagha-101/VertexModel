# Simulation of a Vertex Model of cells 
Vertex model simulations using C++ involves modeling the mechanical interactions between cells and their vertices.

### **Vertex Model**
   Active Vertex Model (AVM) is a computational approach used to simulate the mechanical behavior of cells in a tissue. Cells are represented as polygons (typically in 2D), with vertices that can move. Vertices are connected by edges, defining the cell boundaries. The system evolves by minimizing an energy function, which includes terms for cell area, perimeter, and other properties.  

### **Cell Polarity**
   Cell polarity refers to the intrinsic asymmetry observed in cells, either in their shape, structure or organization of cellular components. It is involved in almost all physiological and developmental processes.

First, we will focus on modelling cell alignment. Here are a few annotations about collective motion that seem interesting:   

“To the physicist, they are also highly nontrivial because they occur without any leader, external field, or geometrical constraint: collective motion can then be seen as the long-range orientational order following spontaneous symmetry-breaking.” ([Chaté et al., 2008, p. 451](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=2&annotation=G2Y7HZSS))

“Medical doctors try to understand tumor growth or wound healing, two situations in which cells move collectively.” ([Chaté et al., 2008, p. 451](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=2&annotation=NPFLBEMR))

“It is only recently (say fifteen years ago) that physicists, in their usual abrupt manner, approached the problem of collective motion by stripping it down to simple experiments or models having in mind the spontaneous symmetry-breaking picture mentioned above.” ([Chaté et al., 2008, p. 451](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=2&annotation=J7MXSE8B))

““Vicsek model” (VM)— is central because of its “minimal” character. In short, in the VM, point particles move at fixed velocity, align locally with neighbors, while being submitted to some noise. In other words, an XY model in which the spins are actively moving.” ([Chaté et al., 2008, p. 451](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=2&annotation=6YCHDXWZ))

“we argue that the focal nature of the VM calls for it being extended, expanded, along three main directions in order to account for most of the different types of collective motion listed above. These are – to vary the polarity of the particles and of their interaction – to introduce a attraction/repulsion pairwise interaction to allow for cohesion – to take into account the ambient fluid in which the particles move” ([Chaté et al., 2008, p. 451](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=2&annotation=IDKY9N8W))

“The two main parameters of the VM are ρ, the density of particles, and η, the noise strength. At zero noise, perfect alignment eventually settles in the whole system (at least if the particles evolve in a domain with periodic “boundary conditions). At maximum noise (η =1),particles are just non-interacting random walkers. Thus, a transition must occur in between.” ” ([Chaté et al., 2008, p. 452](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=3&annotation=BZ4RXMDW))

“Vicsek-style models can also be constructed in which the symmetry of the particles differ from that of their interactions.” ([Chaté et al., 2008, p. 453](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=4&annotation=GKQIJ6HM))

“Indeed, when thinking, say, of shaken elongated polar granular particles, it is likely that their inelastic collisions are rather nematic than purely polar: when colliding almost head-on, they will glide along each other rather than align.” ([Chaté et al., 2008, p. 453](zotero://select/library/items/P3P4P9UJ)) ([pdf](zotero://open-pdf/library/items/6VPI6EWX?page=4&annotation=GE7GD9XK)) 

### References
Barton, D. L., Henkes, S., Weijer, C. J., & Sknepnek, R. (2017). Active vertex model for cell-resolution description of epithelial tissue mechanics. PLOS Computational Biology, 13(6). https://doi.org/10.1371/journal.pcbi.1005569 

Fletcher, A. G., Osterfield, M., Baker, R. E., & Shvartsman, S. Y. (2014). Vertex models of epithelial morphogenesis. Biophysical journal, 106(11), 2291–2304. https://doi.org/10.1016/j.bpj.2013.11.4498
