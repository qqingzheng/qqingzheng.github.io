# gNB SRS处理

```python
    def Process_SRS(self,SRS_p1,SRS_p2,ue_id,port):
        Coma_p1 = SRS_p1.T@SRS_p1
        Coma_p2 = SRS_p2.T@SRS_p2
        Tra_p1 = np.trace(Coma_p1)
        Tra_p2 = np.trace(Coma_p2)
        a1 = Tra_p1/(Tra_p1+Tra_p2)
        a2 = Tra_p2/(Tra_p1+Tra_p2)
        Coma_Short = a1*Coma_p1 + a2*Coma_p2
        self.Coma_Short[ue_id] = Coma_Short
        self.Coma_Long[ue_id] = self.alpha*self.Coma_Long[ue_id] + (1-self.alpha)*Coma_Short
        self.SRSs[ue_id,port] = np.concatenate((SRS_p1,SRS_p2),axis=1)
```

## 1.计算Coma

$$

Coma_{p_k} = (SRS_{p_k},SRS_{p2_k})

$$

## 2.计算矩阵的迹

$$

Tra_{p_k} = Trace(Coma_{p_k})

$$

## 3.计算a值

$$

a_k = \frac{Tra_{p_k}}{(Tra_{p_1} +Tra_{p_2})}

$$

## 4.计算Coma Instant

$$

InstantComa = \sum^{2}_{k=1}a_kTra_{p_k}

$$

## 5.更新Coma Long

$$

LtComa = \alpha*LtComa + (1-\alpha)*InstantComa

$$