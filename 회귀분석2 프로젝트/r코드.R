install.package("devtools")
library(devtools)
library(regbook)
data = read.csv("C:\\dat_train.csv")
dataa = within(data, {
  Sex = factor(Sex, labels=c("woman", "man"))
  smoking = factor(smoking > 0) # = TRUE if smoking > 0, = FALSE if smoking = 0
  HTN = factor(HTN > 0) # = TRUE if HTN > 0, = FALSE if HTN = 0
  DM = factor(DM > 0) # = TRUE if DM > 0, = FALSE if DM = 0
})
HL <- hdl+LDL
plot(TCHOL~HL)
cor(TCHOL~HL)
TCHOL - HL
data <- dataa[c(-13, -20, -36, -52, -64, -129, -176, -229,
-348, -357, -447, -450, -521, -542,-642,-681,-736),]
attach(data)
NL <- neutrophil+lymphocyte 
plot(WBC~NL)
cor(WBC,NL)
NL
data <- data[c(-201,-512),]
attach(data)
N_L <- neutrophil/lymphocyte
fit <- glm(formula = CADGROUP ~ age + hdl + LDL + log(N_L)+ WBC, family = binomial(link = "logit"), 
    data = data, trace = TRUE)
fit2 <- step(fit, scope = ~ age + hdl + LDL + log(N_L)+ WBC+ Sex+smoking+HTN+hemoglobin+DM,direction="both")
summary(fit2)
tem <- lm(LDL~age+hdl+log(N_L)+WBC+smoking+Sex+DM+hemoglobin,data)
summary(tem)
comfit <- glm(formula = CADGROUP ~ age  + log(N_L) + WBC + smoking + Sex+
      DM + LDL + LDL:Sex + LDL:DM + LDL:smoking, family = binomial(link = "logit"), 
    data = data, trace = TRUE)
summary(comfit)
comfit2 <- glm(formula = CADGROUP ~ age  + log(N_L) + WBC + smoking +
    LDL + LDL:Sex + LDL:DM , family = binomial(link = "logit"),
    data = data, trace = TRUE)
summary(comfit2)
vif(comfit2)
plot(comfit2,which=4)
abline(h=0.005)
influence.measures(comfit2)
ddata <- dataa[c(-7,-13,-15,-20,-22,-36,-50,-52,-64,-86,-111,-129,-134,-149,-170,
  -175,-176,-211,-212,-225,-229,-271,-292,-311,-338,-348,-357,-358,-380,-413,
  -418,-447,-450,-521,-542,-560,-587,-593,-640,-642,-663,-681,-736,-744),]
attach(ddata)
N_L <- neutrophil/lymphocyte
comfit3 <- glm(formula = CADGROUP ~ age  + log(N_L) + WBC + smoking +
    LDL + LDL:Sex + LDL:DM , family = binomial(link = "logit"),
    data = ddata, trace = TRUE)
summary(comfit3)


par(mfrow=c(2,4))
agebox=boxplot(data$age)
TCHOLbox=boxplot(data$TCHOL)
hdlbox=boxplot(data$hdl)
LDLbox=boxplot(data$LDL)
hemoglobinbox=boxplot(data$hemoglobin)
WBCbox=boxplot(data$WBC)
neutrophilbox=boxplot(data$neutrophil)
lymphocytebox=boxplot(data$lymphocyte)
data=data[-which(data$TCHOL >= 284),]
data=data[-which(data$age <= 25),]
data=data[-which(data$hdl >= 71),]
data=data[-which(data$LDL >= 175.5),]
data=data[-which(data$hemoglobin <= 8.65),]
data=data[-which(data$hemoglobin >= 17.85),]
data=data[-which(data$WBC >= 12860),]
data=data[-which(data$neutrophil >= 86.35),]
data=data[-which(data$neutrophil <= 27.55),]
data=data[-which(data$lymphocyte >= 59.65),]





fullfit <- glm(formula = CADGROUP ~ ., family = binomial(link = "logit"),data = dataa, trace = TRUE)
stepAIC(fullfit)
aicfit<- glm(formula = CADGROUP ~ age+Sex+smoking+LDL+WBC+lymphocyte+DM, family = binomial(link = "logit"),data = dataa, trace = TRUE)
summary(aicfit)

comfit5 <- glm(formula = CADGROUP ~ age  + log(neutrophil/lymphocyte) + WBC + smoking +LDL + LDL:Sex + LDL:DM , family = binomial(link = "logit"),data = dataa, trace = TRUE)
summary(comfit5)






n=500
j=0
pred2=array(
   data=NA, 
   dim=length(n),  
   dimnames=NULL      
)

pressfit=array(
   data=0, 
   dim=length(n),  
   dimnames=NULL      
)

N=nrow(dataa)
k=sample(1:N,N*8/9)
train=dataa[k,]
valid=dataa[-k,]

for(i in 1:n){
N=nrow(train)
k=sample(1:N,N*1/2)
train2=dataa[k,]
valid2=dataa[-k,]
presfit <- glm(formula = CADGROUP ~ age  + log(neutrophil/lymphocyte) + WBC + smoking +LDL + LDL:Sex + LDL:DM , family = binomial(link = "logit"),data = train2, trace = TRUE)
pred <- predict(presfit, valid2,type="response")>=0.5
table(pred, valid2[,1])
pred2[i]= sum(diag(table(pred, valid2[,1])))/ sum(table(pred, valid2[,1]))
pressfit[i] <- glm(formula = CADGROUP ~ age  + log(neutrophil/lymphocyte) + WBC + smoking +LDL + LDL:Sex + LDL:DM , family = binomial(link = "logit"),data = train2, trace = TRUE)
}
max(pred2)

l=0
for(i in 1:n){
if(max(pred2)==pred2[i]){
  l=i
}
}
pressfit[l]  
# Y = -3.180947 +0.0262292*age+0.4812328*log(neutrophil/lymphocyte)+0.00002908111*WBC+2.242741*smoking+0.003664049*LDL-0.0263592*LDL*Sex+0.008107566*DM

