# GetChannel函数分析

```python
def get_channel(H_angles=[], V_angles=[], numHant=8, numVant=4, HSpacing=0.5, VSpacing=0.7,downtilt=0):
  HAnt_pos = HSpacing * np.repeat(np.expand_dims(np.arange(0, numHant), 0), numVant, 0)
  VAnt_pos = VSpacing * np.repeat(np.expand_dims(np.arange(0, numVant), 1), numHant, 1)
```
HAnt_pos与VAnt_pos为获取所有天线距离第一个天线的x坐标与y坐标。
```python
  HAnt_pos = np.reshape(HAnt_pos,(-1,1))
  HAnt_pos = HAnt_pos.transpose(1,0)
  VAnt_pos = np.reshape(VAnt_pos,(1,-1))
```
将他们转为列向量。
```
  ## add V_shift
  # VAntennaPositions = reshape(VAntennaPositions,numHAntennas,[]);
  # VAntennaPositions(2:2:end) = VAntennaPositions(2:2:end)+VShift;
  # VAntennaPositions = reshape(VAntennaPositions,1,[]);
  H_channel_angles = np.repeat(np.expand_dims(H_angles, 1), V_angles.size, 1)
  V_channel_angles = np.repeat(np.expand_dims(V_angles, 0), H_angles.size, 0)
  H_channel_angles = 90-H_channel_angles

  [H_channel_angles, V_channel_angles] = AngleFromLtoG(H_channel_angles, V_channel_angles, downtilt)
  H_channel_angles = 90 - H_channel_angles
  H_channel_angles = np.reshape(H_channel_angles,(-1,1))
  V_channel_angles = np.reshape(V_channel_angles,(1,-1))
  V_channel_angles = V_channel_angles.transpose(1,0)
  channel = np.exp(1j*2*pi*(np.sin(H_channel_angles/180*pi)*np.cos(V_channel_angles/180*pi)@HAnt_pos+np.sin(V_channel_angles/180*pi)@VAnt_pos))
  ## AEPattern
  H_min = 12*(H_channel_angles/65)**2
  H_min[H_min>30] = 30
  V_min = 12*(V_channel_angles/65)**2
  V_min[V_min>30] = 30
  channel = (np.diag(np.power(10,(8*np.ones_like(H_channel_angles) - H_min - V_min)/20).squeeze(axis=-1)))@channel
  # # channel = np.reshape(channel,(-1,numHant*numVant))

  ## add pattern
  # H_pattern = 10*log10(H_pattern);
  # V_pattern = 10*log10(V_pattern);
  # if isAEPattern
  #     if ~isempty(H_pattern)
  #         channel = diag(10.^((H_pattern(floor(mod(360+HChannelAngles,360))+1)+V_pattern(floor(mod(360-VChannelAngles,360))+1))/20))*channels;
  #     else
  #         channel = diag(10.^((8-min(12*(HChannelAngles/65).^2,30)-min(12*(VChannelAngles/65).^2,30))/20))*channel;
  #     end
  # end
  # angles = size(channel,1);
  # for i = 1:angles
  #     channel(i,:) = channel(i,:).*reshape(combiningWeight_complex,1,[]);
  # end
  return channel

def AngleFromLtoG(H_angle,V_angle,downtilt):
  H_angle = H_angle/180*pi
  V_angle = V_angle/180*pi
  downtilt = downtilt/180*pi
  [lx,ly,lz] = sph2cart(H_angle,V_angle,1)
  R = np.array([[1,0,0],
       [0,np.cos(downtilt),-np.sin(downtilt)],
       [0,np.sin(downtilt),np.cos(downtilt)]]) 
  R = np.linalg.inv(R)
  L = np.array([lx,ly,lz])
  L = np.expand_dims(L,0)
  L = np.transpose(L)
  G = R@L
  G = np.transpose(G)
  G = G[0]
  [H_angle,V_angle,r] = cart2sph(G[0],G[1],G[2]) 
  H_angle = H_angle/pi*180
  V_angle = V_angle/pi*180
  return H_angle,V_angle

def sph2cart(az, el, r):
  rcos_theta = r * np.cos(el)
  x = rcos_theta * np.cos(az)
  y = rcos_theta * np.sin(az)
  z = r * np.sin(el)
  return x, y, z
  
def cart2sph(x, y, z):
  hxy = np.hypot(x, y)
  r = np.hypot(hxy, z)
  el = np.arctan2(z, hxy)
  az = np.arctan2(y, x)
  return az, el, r
  

```