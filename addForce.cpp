using UnityEngine;
public class addForce : MonoBehaviour
{
    public Rigidbody rb;
    void FixedUpdate()
    {
        if (Input.GetKey("w")) 
        { 
            rb.AddForce(0, 800, 800); 
        }
       
    }
}
