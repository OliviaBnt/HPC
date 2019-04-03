#Passage a l'échelle forte
#Addition
temps1M = c(23, 22, 27, 29)
temps10M= c(210, 214, 256, 248)
nbcoeur = c(1, 2, 4, 8)

limin <- min(temps1M, temps10M)
limax <- max(temps1M, temps10M)

plot(nbcoeur, temps1M,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
      las = 1, xaxt="n", main="Echelle forte : Addition de deux vecteurs ", col="steelblue3")
axis(1, at = c(seq(1, 8, by = 1), las=1))
lines(nbcoeur, temps10M, type="o", lwd = 2, col="indianred1")
legend("right", inset = 0.02, legend=c("Vecteur 1M", "Vecteur 10M"), col=c("steelblue3", "indianred1"), lty=1, lwd = 2, cex = 0.9)


#Somme
temps1M=c(22, 20, 20, 23, 22)
temps10M=c(203, 203, 212, 208, 207)
nbcoeur = c(1, 2, 4, 8, 16)
limin <- min(temps1M, temps10M)
limax <- max(temps1M, temps10M)

plot(nbcoeur, temps1M,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
     las = 1, xaxt="n", main="Echelle forte : Somme des cases d'un vecteur ", col="steelblue3")
axis(1, at = c(seq(0, 16, by = 2), las=1))
lines(nbcoeur, temps10M, type="o", lwd = 2, col="indianred1")
legend("right", inset = 0.02, legend=c("Vecteur 1M", "Vecteur 10M"), col=c("steelblue3", "indianred1"), lty=1, lwd = 2, cex = 0.9)


#Passage a l'échelle faible
#10M
#Addtion
tempsXM= c(210, 431, 1039)
nbcoeur = c(1, 2, 4)
limin <- min(tempsXM, tempsXM)
limax <- max(tempsXM, tempsXM)

plot(nbcoeur, tempsXM,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
     las = 1, xaxt="n", main="Echelle faible : Addition vecteurs taille croissante", col="steelblue3")
axis(1, at = c(seq(1, 8, by = 1), las=1))

#Somme
tempsXM=c(204, 408, 825)
nbcoeur = c(1, 2, 4)
limin <- min(tempsXM, tempsXM)
limax <- max(tempsXM, tempsXM)

plot(nbcoeur, tempsXM,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
     las = 1, xaxt="n", main="Echelle faible : Somme cases vecteur taille croissante", col="steelblue3")
axis(1, at = c(seq(2, 16, by = 2), las=1))

###Multiplication
#Forte

temps1M= c(21,20,20)
temps10M= c(199,202,202)
nbcoeur = c(1, 2, 4)
limin <- min(temps1M, temps10M)
limax <- max(temps1M, temps10M)

plot(nbcoeur, temps1M,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
     las = 1, xaxt="n", main="Echelle forte : Multiplication par un double ", col="steelblue3")
axis(1, at = c(seq(1, 8, by = 1), las=1))
lines(nbcoeur, temps10M, type="o", lwd = 2, col="indianred1")
legend("right", inset = 0.02, legend=c("Vecteur 1M", "Vecteur 10M"), col=c("steelblue3", "indianred1"), lty=1, lwd = 2, cex = 0.9)

#Faible

tempsXM=c(199, 398, 837)
nbcoeur = c(1, 2, 4)
limin <- min(tempsXM, tempsXM)
limax <- max(tempsXM, tempsXM)

plot(nbcoeur, tempsXM,  ylim = range(limin:limax),  type = "o", xlab = "Nombre de coeurs", ylab = "Temps d'exécution (en ms)", lwd = 2,
     las = 1, xaxt="n", col="steelblue3")
axis(1, at = c(seq(2, 16, by = 2), las=1))
title(main=paste("Echelle faible : Multiplication vecteur taille","\n",sep=""),cex.main=1.3)
title(main=paste("\n","croissante par un double",sep=""),cex.main=1.3)




####MATRICES######
