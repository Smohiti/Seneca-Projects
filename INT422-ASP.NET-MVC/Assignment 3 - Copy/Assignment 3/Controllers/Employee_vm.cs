using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace Assignment_3.Controllers
{
    public class EmployeeAdd
    {
        public EmployeeAdd()
        {
            HireDate = DateTime.Now;
            BirthDate = DateTime.Now.AddYears(-25);
        }

        [Required]
        [StringLength(20)]
        [Display(Name = "Last Name")]
        public string LastName { get; set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "First Name")]
        public string FirstName { get; set; }

        [StringLength(30)]
        public string Title { get; set; }
        [Display(Name = "Birth Date")]
        public DateTime? BirthDate { get; set; }
        [Display(Name = "Hire Date")]
        public DateTime? HireDate { get; set; }

        [StringLength(70)]
        public string Address { get; set; }

        [StringLength(40)]
        public string City { get; set; }

        [StringLength(40)]
        public string State { get; set; }

        [StringLength(40)]
        public string Country { get; set; }

        [StringLength(10)]
        [Display(Name = "Postal Code")]
        public string PostalCode { get; set; }

        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }

        [StringLength(60)]
        [Display(Name = "Email Address")]
        public string Email { get; set; }

    }


    public class EmployeeBase : EmployeeAdd
    {
        // Constructor, for setting reasonable initial values
        public EmployeeBase() { }

        // Notice that we must identify the key/identifier with a [Key] data annotation
        [Key]
        public int EmployeeId { get; set; }
    }


    public class EmployeeEditContactInfoForm
    {
        public EmployeeEditContactInfoForm() { }

        [Key]
        public int EmployeeId { get; set; }

        // In the view, we will display this info
        [Required]
        [StringLength(20)]
        [Display(Name = "Last Name")]
        public string LastName { get; set; }

        [Required]
        [StringLength(20)]
        [Display(Name = "First Name")]
        public string FirstName
        {
            get; set;
        }

        [StringLength(40)]
        public string Address { get; set; }

        // In the view, we will display this info

        [StringLength(20)]
        public string City { get; set; }


        [StringLength(20)]
        public string State { get; set; }

        [StringLength(20)]

        public string Country { get; set; }

        [StringLength(20)]
        [Display(Name = "Postal Code")]
        public string PostalCode { get; set; }

        // In the view, we will display this info


        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }
        [Display(Name = "Email Address")]
        [StringLength(60)]
        public string Email { get; set; }
        [Range(2, 6)]
        [Display(Name = "Number of vacation")]
        public int Vacation { get; set; }
        [DataType(DataType.Password)]
        public string Password { get; set; }




    }
    public class EmployeeEditContactInfo
    {
        public EmployeeEditContactInfo() { }

        [Key]
        public int EmployeeId { get; set; }
        [StringLength(50)]
        public string Address { get; set; }
        [StringLength(24)]
        public string Phone { get; set; }

        [StringLength(24)]
        public string Fax { get; set; }
        [StringLength(60)]
        [Display(Name = "Email Address")]
        public string Email { get; set; }




    }




}