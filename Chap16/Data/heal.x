xof 0303txt 0064

// Created with Milkshape 3D DirectX .X File Exporter V2.0
// Copyright (c) 2001 by Jim Adams.  All Rights Reserved.

Header {
  1;
  0;
  1;
}

Frame SceneRoot {
  Frame Sparkle1 {
    FrameTransformMatrix {
      1.000000,0.000000,0.000000,0.000000,
      0.000000,1.000000,0.000000,0.000000,
      0.000000,0.000000,1.000000,0.000000,
      0.000000,0.000000,0.000000,1.000000;;
    }
    Mesh Sparkle01 {
      4;
      -40.000000;60.000000;0.000000;,
       40.000000;60.000000;0.000000;,
      -40.000000; 0.000000;0.000000;,
       40.000000; 0.000000;0.000000;;
      4;
      3;0,1,2;,
      3;1,3,2;,
      3;2,1,0;,
      3;2,3,1;;
      MeshTextureCoords {
        4;
        0.000000;0.000000;,
        1.000000;0.000000;,
        0.000000;1.000000;,
        1.000000;1.000000;;
      }
      MeshMaterialList {
        1;
        4;
        0,
        0,
        0,
        0;;
        Material Material01 {
          1.000000;1.000000;1.000000;0.500000;;
          1.000000;
          0.000000;0.000000;0.000000;;
          0.000000;0.000000;0.000000;;
          TextureFilename {
            "Heal.bmp";
          }
        }
      }
    }
  }
  Frame Sparkle2 {
    FrameTransformMatrix {
      1.000000,0.000000,0.000000,0.000000,
      0.000000,1.000000,0.000000,0.000000,
      0.000000,0.000000,1.000000,0.000000,
      0.000000,0.000000,0.000000,1.000000;;
    }
    Mesh Sparkle02 {
      4;
      0.000000;60.000000;-40.000000;,
      0.000000;60.000000; 40.000000;,
      0.000000; 0.000000;-40.000000;,
      0.000000; 0.000000; 40.000000;;
      4;
      3;0,1,2;,
      3;1,3,2;,
      3;2,1,0;,
      3;2,3,1;;
      MeshTextureCoords {
        4;
        0.000000;0.000000;,
        1.000000;0.000000;,
        0.000000;1.000000;,
        1.000000;1.000000;;
      }
      MeshMaterialList {
        1;
        4;
        0,
        0,
        0,
        0;;
        {Material01}
      }
    }
  }
  Frame Sparkle3 {
    FrameTransformMatrix {
      1.000000,0.000000,0.000000,0.000000,
      0.000000,1.000000,0.000000,0.000000,
      0.000000,0.000000,1.000000,0.000000,
      0.000000,0.000000,0.000000,1.000000;;
    }
    Mesh Sparkle03 {
      4;
      -40.000000;30.000000;40.000000;,
       40.000000;30.000000;40.000000;,
      -40.000000;30.000000;-40.000000;,
       40.000000;30.000000;-40.000000;;
      4;
      3;0,1,2;,
      3;1,3,2;,
      3;2,1,0;,
      3;2,3,1;;
      MeshTextureCoords {
        4;
        0.000000;0.000000;,
        1.000000;0.000000;,
        0.000000;1.000000;,
        1.000000;1.000000;;
      }
      MeshMaterialList {
        1;
        4;
        0,
        0,
        0,
        0;;
        {Material01}
      }
    }
  }
}

AnimationSet Anim {
  Animation {
    {Sparkle1}
    AnimationKey {
      4;
      3;
      0; 16;  1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,1.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
      8; 16;  0.000000,0.000000,-1.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              1.000000,0.000000,0.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
      16; 16; -1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,-1.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;;
    }
  }
  Animation {
    {Sparkle2}
    AnimationKey {
      4;
      3;
      0; 16;  1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,1.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
      8; 16;  0.000000,0.000000,1.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              -1.000000,0.000000,0.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
      16; 16; -1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,-1.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
    }
  }
  Animation {
    {Sparkle3}
    AnimationKey {
      4;
      3;
      0; 16;  1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,1.000000,0.000000,
              0.000000,0.000000,0.000000,1.000000;;,
      8; 16;  0.000000,0.000000,-1.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              1.000000,0.000000,0.000000,0.000000,
              0.000000,20.000000,0.000000,1.000000;;,
      16; 16; -1.000000,0.000000,0.000000,0.000000,
              0.000000,1.000000,0.000000,0.000000,
              0.000000,0.000000,-1.000000,0.000000,
              0.000000,40.000000,0.000000,1.000000;;;
    }
  }
}
