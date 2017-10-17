using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Web;

namespace Assignment_4.Controllers
{
    public class InvoiceBase
    {
        public InvoiceBase() { }
        [Key]
        [Display(Name = "Invoice Id")]
        public int InvoiceId { get; set; }
        [Display(Name = "Customer Id")]
        public int CustomerId { get; set; }
        [Display(Name = "Invoice Date")]
        public DateTime InvoiceDate { get; set; }
        [Display(Name = "Billing Address")]
        public string BillingAddress { get; set; }
        [Display(Name = "Billing City")]
        public string BillingCity { get; set; }
        [Display(Name = "Billing Country")]
        public string BillingCountry { get; set; }
        [Display(Name = "Billing state")]
        public string Billingstate { get; set; }
        [Display(Name = "Postal Code")]
        public string BillingPostalCode { get; set; }
        [Display(Name = "Invoice Total")]
        public decimal Total { get; set; }


    }
    public class InvoiceWithDetail : InvoiceBase
    {

        public string CustomerFirstName { get; set; }
        public string CustomerLastName { get; set; }
        public string CustomerCity { get; set; }
        public string CustomerState { get; set; }
        public string CustomerEmployeeFirstName { get; set; }
        public string CustomerEmployeeLastName { get; set; }
        public ICollection<InvoiceLineWithDetail> InvoiceLines { get; set; }
    }
    public class InvoiceLineBase
    {

        public int InvoiceId { get; set; }
        public int InvoiceLineId { get; set; }
        public int TrackId { get; set; }

        public decimal UnitPrice { get; set; }
        public int Quantity { get; set; }
    }
    public class InvoiceLineWithDetail : InvoiceLineBase
    {
        public string TrackComposer { get; set; }

        public string TrackName { get; set; }

        public string TrackAlbumTitle { get; set; }

        public string TrackAlbumArtistName { get; set; }

        public string TrackMediaTypeName { get; set; }
    }


}